/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/*Que. Write a menu driven program that will execute on STM32. It should display menu on UART (Putty/Minicom) and take user choice from there. As per user
choice perform the operation. Provide following menu functionalities. Implement program using UART Polling.
1. Red Led On
2. Red Led Off
3. Blue Led On
4. Blue Led Off
*/

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)

{
	char ch = 0 ;
	SystemInit();
	LedInit(LED_BLUE);
	LedInit(LED_RED);
	UartInit(BAUD_9600);

	while(1) {

		UartPuts("Enter your choice \r\n1.RED LED ON\r\n2.RED LED OFF\r\n3.BLUE LED ON\r\n4.BLUE LED OFF\r\n");
		ch = UartGetch();
        switch(ch)
        {
           case '1':
        	     LedOn(LED_RED);
        	     break;

           case '2':
        	     LedOff(LED_RED);
        	     break;

           case '3':
        	     LedOn(LED_BLUE);
        	     break;

           case '4':
        	     LedOff(LED_BLUE);
        	     break;
        }

        ch = 0;
	}
	return 0;
}
