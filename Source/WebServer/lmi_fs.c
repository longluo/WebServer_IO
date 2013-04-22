//*****************************************************************************
//
// lmi_fs.c - File System Processing for enet_io application.
//
//*****************************************************************************

#include <string.h>
#include "hw_types.h"
#include "hw_memmap.h"
#include "gpio.h"
#include "lwiplib.h"
#include "fs.h"
#include "fsdata.h"
#include "uartstdio.h"
#include "ustdlib.h"
#include "temperature_sensor.h"


//*****************************************************************************
//
// Include the file system data for this application.  This file is generated
// by the makefsfile utility, using the following command (all on one line):
//
//     makefsfile -i fs -o io_fsdata.h -r -h
//
// If any changes are made to the static content of the web pages served by the
// application, this script must be used to regenerate io_fsdata.h in order
// for those changes to be picked up by the web server.
//
//*****************************************************************************
#include "io_fsdata.h"
extern unsigned long ulTemp_ValueC;

//*****************************************************************************
//
// Global Settings for demo page content.
//
//*****************************************************************************
//static char g_cSampleTextBuffer[17] = {0};

//*****************************************************************************
//
// Open a file and return a handle to the file, if found.  Otherwise,
// return NULL.  This function also looks for special filenames used to
// provide specific status information or to control various subsystems.
// These filenames are used by the JavaScript on the "IO Control Demo 1"
// example web page.
//
//*****************************************************************************
struct fs_file *
fs_open(char *name)
{
	const struct fsdata_file *ptTree;
	struct fs_file *ptFile = NULL;

	//
	// Allocate memory for the file system structure.
	//
	ptFile = mem_malloc(sizeof(struct fs_file));
	if (NULL == ptFile)
	{
		return(NULL);
	}

	if (strncmp(name, "/gettemp?id", 11) == 0)
	{
		static char pcBuf[16];
		usprintf(pcBuf, "%d", io_gettemp());
		ptFile->data = pcBuf;
		ptFile->len = strlen(pcBuf);
		ptFile->index = ptFile->len;
		ptFile->pextension = NULL;
		
		return(ptFile);
	}

	//
	// If I can't find it there, look in the rest of the main file system
	//
	else
	{
		//
		// Initialize the file system tree pointer to the root of the linked list.
		//
		ptTree = FS_ROOT;
		UARTprintf("Loading the index.htm...");
		
		//
		// Begin processing the linked list, looking for the requested file name.
		//
		while (NULL != ptTree)
		{
			//
			// Compare the requested file "name" to the file name in the
			// current node.
			//
			if (strncmp(name, (char *)ptTree->name, ptTree->len) == 0)
			{
				//
				// Fill in the data pointer and length values from the
				// linked list node.
				//
				ptFile->data = (char *)ptTree->data;
				ptFile->len = ptTree->len;

				//
				// For now, we setup the read index to the end of the file,
				// indicating that all data has been read.
				//
				ptFile->index = ptTree->len;

				//
				// We are not using any file system extensions in this
				// application, so set the pointer to NULL.
				//
				ptFile->pextension = NULL;

				//
				// Exit the loop and return the file system pointer.
				//
				break;
			}

			//
			// If we get here, we did not find the file at this node of the linked
			// list.  Get the next element in the list.
			//
			ptTree = ptTree->next;
		}
	}

	//
	// If we didn't find the file, ptTee will be NULL.  Make sure we
	// return a NULL pointer if this happens.
	//
	if(NULL == ptTree)
	{
		mem_free(ptFile);
		ptFile = NULL;
	}

	//
	// Return the file system pointer.
	//
	return(ptFile);
}


//*****************************************************************************
//
// Close an opened file designated by the handle.
//
//*****************************************************************************
void
fs_close(struct fs_file *file)
{
    //
    // Free the main file system object.
    //
    mem_free(file);
}


//*****************************************************************************
//
// Read the next chunck of data from the file.  Return the count of data
// that was read.  Return 0 if no data is currently available.  Return
// a -1 if at the end of file.
//
//*****************************************************************************
int
fs_read(struct fs_file *file, char *buffer, int count)
{
    int iAvailable;

    //
    // Check to see if a command (pextension = 1).
    //
    if(file->pextension == (void *)1)
    {
        //
        // Nothting to do for this file type.
        //
        file->pextension = NULL;
        return(-1);
    }

    //
    // Check to see if more data is available.
    //
    if(file->len == file->index)
    {
        //
        // There is no remaining data.  Return a -1 for EOF indication.
        //
        return(-1);
    }

    //
    // Determine how much data we can copy.  The minimum of the 'count'
    // parameter or the available data in the file system buffer.
    //
    iAvailable = file->len - file->index;
    if(iAvailable > count)
    {
        iAvailable = count;
    }

    //
    // Copy the data.
    //
    memcpy(buffer, file->data + iAvailable, iAvailable);
    file->index += iAvailable;

    //
    // Return the count of data that we copied.
    //
    return(iAvailable);
}

