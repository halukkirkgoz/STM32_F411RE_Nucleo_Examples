/*
 * 004_Onboard_LED_Toggle_with_ITM_Hello_World.c
 *
 *  Created on: Jun 23, 2026
 */

/* Includes */
#include <stdio.h>
#include <inttypes.h>
#include "itm_send_data.h"
#include "stm32f411xe_gpio.h"

/* Definitions */

/* Globals */

/* Function Prototypes */
void delay_with_loop(void);

/************/
int main(void)
{
	ITM_Init();
	uint32_t counter = 0;

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

	printf("%s\r\n", "Hello World!");

	// Loop forever
	while (1) {
		GPIO_WriteToOutputPin(PA5_LED.GPIOx, PA5_LED.GPIOx_PinConfig.GPIO_PinNumber, GPIO_SET);
		delay_with_loop();
		GPIO_WriteToOutputPin(PA5_LED.GPIOx, PA5_LED.GPIOx_PinConfig.GPIO_PinNumber, GPIO_RESET);
		delay_with_loop();
		printf("Counter = %" PRIu32 "\r\n", counter++);
	}
}

/* Simple static software delay function */
void delay_with_loop(void)
{
	for (volatile uint32_t i = 0; i < 1000000; i++) {
		__asm volatile("nop");
	}
}
