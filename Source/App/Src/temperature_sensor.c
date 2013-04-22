/************************************************************************************
** File: - E:\ARM\lm3s8962projects\WebIO\Source\App\Src\temperature_sensor.c
**  
** Copyright (C), Long.Luo, All Rights Reserved!
** 
** Description: 
**      Get the chip's temperature.
** 
** Version: 1.1
** Date created: 10:57:32,20/04/2013
** Author: Long.Luo
** 
** --------------------------- Revision History: --------------------------------
** 	<author>	<data>			<desc>
** 
************************************************************************************/

#include "hw_memmap.h"
#include "hw_types.h"
#include "adc.h"
#include "gpio.h"
#include "sysctl.h"

unsigned long io_gettemp(void)
{       
	unsigned long ulTemp_ValueC;
	unsigned long ulADC0_Value[1];
	
	ADCProcessorTrigger(ADC0_BASE, 3);
	while (!ADCIntStatus(ADC0_BASE, 3, false))
	{
	}
	ADCSequenceDataGet(ADC0_BASE, 3, ulADC0_Value);
	ulTemp_ValueC = ((1475 * 1023) - (2250 * ulADC0_Value[0])) / 10230;
	
	return  ulTemp_ValueC;
}


