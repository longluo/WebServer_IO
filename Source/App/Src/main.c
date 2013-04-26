/************************************************************************************
** File: - E:\ARM\lm3s8962projects\WebIO\WebIO\Source\App\Src\main.c
**  
** Copyright (C), Long.Luo, All Rights Reserved!
** 
** Description: 
**      the main of WebIO
** 
** Version: 2.1
** Date created: 16:00:52,14/04/2013
** Author: Long.Luo
** 
** --------------------------- Revision History: --------------------------------
** 	<author>	<data>			<desc>
** 
************************************************************************************/

//#include <string.h>
#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_nvic.h"
#include "ethernet.h"
#include "flash.h"
#include "gpio.h"
#include "interrupt.h"
#include "sysctl.h"
#include "systick.h"
#include "adc.h"
#include "lwiplib.h"
#include "uartstdio.h"
#include "ustdlib.h"
#include "httpd.h"
#include "rit128x96x4.h"


//*****************************************************************************
//
// Defines for setting up the system clock.
//
//*****************************************************************************
#define SYSTICKHZ               100
#define SYSTICKMS               (1000 / SYSTICKHZ)
#define SYSTICKUS               (1000000 / SYSTICKHZ)
#define SYSTICKNS               (1000000000 / SYSTICKHZ)


//*****************************************************************************
//
// A set of flags.  The flag bits are defined as follows:
//
//     0 -> An indicator that a SysTick interrupt has occurred.
//
//*****************************************************************************
#define FLAG_SYSTICK            0
static volatile unsigned long g_ulFlags;


//*****************************************************************************
//
// External Application references.
//
//*****************************************************************************
extern void httpd_init(void);


//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
}
#endif


//
// Display an lwIP type IP Address.
//
void DisplayIPAddress(unsigned long ipaddr, unsigned long ulCol,
                 unsigned long ulRow)
{
    char pucBuf[16];
    unsigned char *pucTemp = (unsigned char *)&ipaddr;

    //
    // Convert the IP Address into a string.
    //
    usprintf(pucBuf, "%d.%d.%d.%d", pucTemp[0], pucTemp[1], pucTemp[2],
             pucTemp[3]);

    //
    // Display the string.
    //
    RIT128x96x4StringDraw(pucBuf, ulCol, ulRow, 15);
}


// The interrupt handler for the SysTick interrupt.
void SysTickIntHandler(void)
{
    // Indicate that a SysTick interrupt has occurred.
    HWREGBITW(&g_ulFlags, FLAG_SYSTICK) = 1;

    // Call the lwIP timer handler.
    lwIPTimer(SYSTICKMS);
}


// Required by lwIP library to support any host-related timer functions.
void lwIPHostTimerHandler(void)
{
    static unsigned long ulLastIPAddress = 0;
    unsigned long ulIPAddress;

    ulIPAddress = lwIPLocalIPAddrGet();

    //
    // If IP Address has not yet been assigned, update the display accordingly
    //
    if (ulIPAddress == 0)
    {
        static int iColumn = 6;

        //
        // Update status bar on the display.
        //
        RIT128x96x4Enable(1000000);
        if (iColumn < 12)
        {
            RIT128x96x4StringDraw(" >", 114, 24, 15);
            RIT128x96x4StringDraw("< ", 0, 24, 15);
            RIT128x96x4StringDraw("*",iColumn, 24, 7);
        }
        else
        {
            RIT128x96x4StringDraw(" *",iColumn - 6, 24, 7);
        }

        iColumn += 4;
        if (iColumn > 114)
        {
            iColumn = 6;
            RIT128x96x4StringDraw(" >", 114, 24, 15);
        }
        RIT128x96x4Disable();
    }

    //
    // Check if IP address has changed, and display if it has.
    //
    else if (ulLastIPAddress != ulIPAddress)
    {
        ulLastIPAddress = ulIPAddress;
        RIT128x96x4Enable(1000000);
        RIT128x96x4StringDraw("                       ", 0, 16, 15);
        RIT128x96x4StringDraw("                       ", 0, 24, 15);
        RIT128x96x4StringDraw("IP:   ", 0, 16, 15);
        RIT128x96x4StringDraw("MASK: ", 0, 24, 15);
        RIT128x96x4StringDraw("GW:   ", 0, 32, 15);
        DisplayIPAddress(ulIPAddress, 36, 16);
        ulIPAddress = lwIPLocalNetMaskGet();
        DisplayIPAddress(ulIPAddress, 36, 24);
        ulIPAddress = lwIPLocalGWAddrGet();
        DisplayIPAddress(ulIPAddress, 36, 32);
        RIT128x96x4Disable();
    }
}


// 
int main(void)
{   
    unsigned long ulUser0, ulUser1;
    unsigned char pucMACArray[8];

    //
    // Set the clocking to run directly from the crystal.
    //
 	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_8MHZ);

    //
    // Initialize the OLED display.
    //
  	RIT128x96x4Init(1000000);
    RIT128x96x4StringDraw("Web-Based I/O Control", 0, 0, 15);
    RIT128x96x4StringDraw("The Chip Temperature:", 0, 53, 15);

    //
    // Enable and Reset the Ethernet Controller.
    //
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ETH);
    SysCtlPeripheralReset(SYSCTL_PERIPH_ETH);

    //
    // Enable Port F for Ethernet LEDs.
    //  LED0        Bit 3   Output
    //  LED1        Bit 2   Output
    //
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeEthernetLED(GPIO_PORTF_BASE, GPIO_PIN_2 | GPIO_PIN_3);
	
    //
    // Configure SysTick for a periodic interrupt.
    //
	SysTickPeriodSet(SysCtlClockGet() / SYSTICKHZ);
    SysTickEnable();
    SysTickIntEnable();

	//
	// Initialize the GPIO Port.
	//
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_0);
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTStdioInit(0);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_TS | ADC_CTL_IE |
                             ADC_CTL_END);
    ADCSequenceEnable(ADC0_BASE, 3);
	ADCIntClear(ADC0_BASE, 3);

    //
    // Enable processor interrupts.
    //
	IntMasterEnable();

    //
    // Configure the hardware MAC address for Ethernet Controller filtering of
    // incoming packets.
    //
    // For the LM3S6965 Evaluation Kit, the MAC address will be stored in the
    // non-volatile USER0 and USER1 registers.  These registers can be read
    // using the FlashUserGet function, as illustrated below.
    //
    FlashUserGet(&ulUser0, &ulUser1);
    if ((ulUser0 == 0xffffffff) || (ulUser1 == 0xffffffff))
    {
        //
        // We should never get here.  This is an error if the MAC address
        // has not been programmed into the device.  Exit the program.
        //
        RIT128x96x4StringDraw("MAC Address", 0, 16, 15);
        RIT128x96x4StringDraw("Not Programmed!", 0, 24, 15);
        while (1);
    }
	
    //
    // Convert the 24/24 split MAC address from NV ram into a 32/16 split
    // MAC address needed to program the hardware registers, then program
    // the MAC address into the Ethernet Controller registers.
    //
    pucMACArray[0] = ((ulUser0 >>  0) & 0xff);
    pucMACArray[1] = ((ulUser0 >>  8) & 0xff);
    pucMACArray[2] = ((ulUser0 >> 16) & 0xff);
    pucMACArray[3] = ((ulUser1 >>  0) & 0xff);
    pucMACArray[4] = ((ulUser1 >>  8) & 0xff);
    pucMACArray[5] = ((ulUser1 >> 16) & 0xff);
    
    //
    // Initialze the lwIP library, using DHCP.
    //
    lwIPInit(pucMACArray, 0, 0, 0, IPADDR_USE_DHCP);
	//lwIPInit(pucMACAddress,ulIPAddr, ulNetMask, ulGWAddr, IPADDR_USE_STATIC);
	
    //
    // Setup the device locator service.
    //
    LocatorInit();
    LocatorMACAddrSet(pucMACArray);
    LocatorAppTitleSet("WebIO");

    //
    // Initialize the httpd server.
    //
	httpd_init();

	while (1)
    {
    
    }

}

