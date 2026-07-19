/*
 * 001_Onboard_LED_Toggle.c
 *
 *  Created on: Jun 18, 2026
 */

/* Includes */
#include "stm32f411xe_gpio.h"

/* Definitions */

/* Globals */

/* Function Prototypes */
void delay_with_loop(void);

/************/
int main(void)
{
	GPIO_Handle_t PA5_LED = {
			.GPIOx = GPIOA,
			.GPIOx_PinConfig = {
					.GPIO_PinNumber = GPIO_PIN_5,
					.GPIO_PinMode = GPIO_MODE_OUTPUT,
					.GPIO_PinOutputType = GPIO_OUTPUT_PUSH_PULL,
					.GPIO_PinOutputSpeed = GPIO_OUTPUT_SPEED_LOW,
					.GPIO_PinPUPD = GPIO_NO_PUPD,
	        }
	};

	GPIO_ClockControl(PA5_LED.GPIOx, ENABLE);
	GPIO_Init(&PA5_LED);
	GPIO_WriteToOutputPin(PA5_LED.GPIOx, PA5_LED.GPIOx_PinConfig.GPIO_PinNumber, GPIO_RESET);

	// Loop forever
	while (1) {
		GPIO_ToggleOutputPin(PA5_LED.GPIOx, PA5_LED.GPIOx_PinConfig.GPIO_PinNumber);
		delay_with_loop();
	}
}

/* Simple static software delay function */
void delay_with_loop(void)
{
	for (volatile uint32_t i = 0; i < 1000000; i++) {
		__asm volatile("nop");
	}
}
