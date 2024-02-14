#include "LED.h"

void LED_Init(void) {
  // Enable GPIO Clock
  RCC->AHB2ENR |= (uint32_t)RCC_AHB2ENR_GPIOAEN;
  RCC->AHB2ENR |= (uint32_t)RCC_AHB2ENR_GPIOCEN;

  // Initialize Green LED
  GPIOA->MODER |= (uint32_t)GPIO_MODER_MODE5_0;
  GPIOA->MODER &= ~(uint32_t)GPIO_MODER_MODE5_1;
  GPIOA->OTYPER &= ~(uint32_t)GPIO_OTYPER_OT5;
  GPIOA->PUPDR &= ~(uint32_t)GPIO_PUPDR_PUPD5_0;
  GPIOA->PUPDR &= ~(uint32_t)GPIO_PUPDR_PUPD5_1;
}

void Green_LED_Off(void) {
	GPIOA->ODR &= ~(uint32_t)GPIO_ODR_OD5;
}

void Green_LED_On(void) {
	GPIOA->ODR |= (uint32_t)GPIO_ODR_OD5;
}

void Green_LED_Toggle(void) {
	GPIOA->ODR ^= (uint32_t)GPIO_ODR_OD5;
}
