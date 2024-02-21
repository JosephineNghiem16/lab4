/*
 * ECE 153B
 *
 * Name(s): Derek Dela Cruz, Josephine Nghiem
 * Section: Tuesday 7pm
 * Lab: 4A
 */


#include "stm32l476xx.h"
#include "LED.h"
#include "SysClock.h"
#include "UART.h"
#include <string.h>
#include <stdio.h>

// Initializes USARTx
// USART2: UART Communication with Termite
// USART1: Bluetooth Communication with Phone
void Init_USARTx(int x) {
	if(x == 1) {
		UART1_Init();
		UART1_GPIO_Init();
		USART_Init(USART1);
	} else if(x == 2) {
		UART2_Init();
		UART2_GPIO_Init();
		USART_Init(USART2);
	} else {
		// Do nothing...
	}
}

int main(void) {
	System_Clock_Init(); // Switch System Clock = 80 MHz
	LED_Init();
	
	// Initialize UART -- change the argument depending on the part you are working on
	Init_USARTx(1);
	
	char rxByte;
	char ans;

	while(1) {	
		printf("Please provide input: Y, y, N, or n\n");
		scanf("%c", &ans);
		
		if ((ans == *"y") || (ans == *"Y")) {
			Green_LED_On();
			printf("LED enabled\n");
		}
		else if ((ans == *"n") || (ans == *"N")) {
			Green_LED_Off();
			printf("LED disabled\n");
		}
		// else if ((ans != *"y") && (ans != *"Y") && (ans != *"n") && (ans != *"N")) {
		else {
			printf("ERROR: unknown command\n");
		}
		
		//Init_USARTx(1);
		
	}
}
