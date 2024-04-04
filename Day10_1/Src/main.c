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

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "i2c_lcd.h"
#include "rtc.h"
#include "uart.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*1. Initialize RTC to 28-Feb-2024 23:59:50. After every second display RTC time on UART (minicom).*/

int main(void)
{
	char str1[24], str2[20];
	RTC_Date d, dt = { .Date = 28, .Month = 02, .Year = 24, .WeekDay = 7 };
	RTC_Time t, tm = { .Hours = 23, .Minutes = 59, .Seconds = 50 };

	SystemInit();
	//LcdInit();
	UartInit(9600);
	UartPuts("The Time and Date is as follows\r\n");
	//LcdPuts(LCD_LINE1, "DESD @ Sunbeam\n");
	//LcdPuts(LCD_LINE2, "STM32 RTC Demo!\n");
	//DelayMs(2000);
	//LcdWrite(LCD_CMD, LCD_CLEAR);
	RTC_Init(&dt, &tm);
	while(1) {
		RTC_GetTime(&t);
		RTC_GetDate(&d);
		sprintf(str1, "DT=%02d-%02d-%02d W=%d\r\n", d.Date, d.Month, d.Year, d.WeekDay);
		sprintf(str2, "TM=%02d:%02d:%02d\r\n", t.Hours, t.Minutes, t.Seconds);
		UartPuts(str1);
		UartPuts(str2);
		DelayMs(1000);
	}
	return 0;
}
