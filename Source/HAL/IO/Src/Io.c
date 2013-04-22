/************************************************************************************
** File: - E:\ARM\lm3s8962projects\WebIO\Source\HAL\IO\Src\Io.c
**  
** Copyright (C), Long.Luo, All Rights Reserved!
** 
** Description: 
**      io.c - I/O routines for the enet_io example application.
** 
** Version: 1.1
** Date created: 23:41:03,14/04/2013
** Author: Long.Luo
** 
** --------------------------- Revision History: --------------------------------
** 	<author>	<data>			<desc>
** 
************************************************************************************/

#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "sysctl.h"
#include "uartstdio.h"
#include "ustdlib.h"
#include "Io.h"


void sendtext2serial(unsigned char *c)
{
	UARTprintf(c);
}


