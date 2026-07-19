/*
 * stm32f411xe_gpio.h
 *
 *  Created on: Jun 16, 2026
 */

#ifndef INC_STM32F411XE_GPIO_H_
#define INC_STM32F411XE_GPIO_H_

/* Includes */
#include "stm32f411xe.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration Structure for a GPIO Pin */
typedef struct {
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinOutputType;
	uint8_t GPIO_PinOutputSpeed;
	uint8_t GPIO_PinPUPD;
	uint8_t GPIO_PinAltFunc;
} GPIO_PinConfig_t;

/* Handle Structure for a GPIO Pin Configuration and Peripheral Base Address */
typedef struct {
	GPIO_RegDef_t *GPIOx;
	GPIO_PinConfig_t GPIOx_PinConfig;
} GPIO_Handle_t;

/* GPIO Pin Number Definitions */
#define GPIO_PIN_0    ((uint8_t) 0UL)
#define GPIO_PIN_1    ((uint8_t) 1UL)
#define GPIO_PIN_2    ((uint8_t) 2UL)
#define GPIO_PIN_3    ((uint8_t) 3UL)
#define GPIO_PIN_4    ((uint8_t) 4UL)
#define GPIO_PIN_5    ((uint8_t) 5UL)
#define GPIO_PIN_6    ((uint8_t) 6UL)
#define GPIO_PIN_7    ((uint8_t) 7UL)
#define GPIO_PIN_8    ((uint8_t) 8UL)
#define GPIO_PIN_9    ((uint8_t) 9UL)
#define GPIO_PIN_10   ((uint8_t) 10UL)
#define GPIO_PIN_11   ((uint8_t) 11UL)
#define GPIO_PIN_12   ((uint8_t) 12UL)
#define GPIO_PIN_13   ((uint8_t) 13UL)
#define GPIO_PIN_14   ((uint8_t) 14UL)
#define GPIO_PIN_15   ((uint8_t) 15UL)

/* GPIO Pin Possible Modes (Standard and Interrupt-triggered) */
#define GPIO_MODE_INPUT      ((uint8_t) 0UL)
#define GPIO_MODE_OUTPUT     ((uint8_t) 1UL)
#define GPIO_MODE_ALTERNATE  ((uint8_t) 2UL)
#define GPIO_MODE_ANALOG     ((uint8_t) 3UL)
#define GPIO_MODE_INPUT_FE   ((uint8_t) 4UL) // Falling Edge Trigger
#define GPIO_MODE_INPUT_RE   ((uint8_t) 5UL) // Rising Edge Trigger
#define GPIO_MODE_INPUT_FERE ((uint8_t) 6UL) // Both Falling and Rising Edge Trigger

/* GPIO Pin Possible Output Types */
#define GPIO_OUTPUT_PUSH_PULL    ((uint8_t) 0UL)
#define GPIO_OUTPUT_OPEN_DRAIN   ((uint8_t) 1UL)

/* GPIO Pin Possible Output Speed Configurations */
#define GPIO_OUTPUT_SPEED_LOW     ((uint8_t) 0UL)
#define GPIO_OUTPUT_SPEED_MEDIUM  ((uint8_t) 1UL)
#define GPIO_OUTPUT_SPEED_FAST    ((uint8_t) 2UL)
#define GPIO_OUTPUT_SPEED_HIGH    ((uint8_t) 3UL)

/* GPIO Pin Possible Pull-Up and Pull-Down Configurations */
#define GPIO_NO_PUPD  ((uint8_t) 0UL)
#define GPIO_PU       ((uint8_t) 1UL)
#define GPIO_PD       ((uint8_t) 2UL)

/* Converts GPIO base address to its corresponding numerical port code for SYSCFG_EXTICR configuration */
#define GPIO_BASEADDR_TO_CODE(x) ((x == GPIOA) ? 0UL :\
                                  (x == GPIOB) ? 1UL :\
                                  (x == GPIOC) ? 2UL :\
                                  (x == GPIOD) ? 3UL :\
                                  (x == GPIOE) ? 4UL :\
                                  (x == GPIOH) ? 7UL : 0UL)

/* Generic Pin Status Definitions */
#define GPIO_SET    SET
#define GPIO_RESET  RESET

/* Function Prototypes */
void GPIO_Init(GPIO_Handle_t *GPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *GPIOx);
void GPIO_ClockControl(GPIO_RegDef_t *GPIOx, uint8_t EnOrDis);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *GPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_PinNumber, uint8_t GPIO_OutputValue);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *GPIOx, uint16_t GPIO_OutputValue);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_PinNumber);
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnOrDis);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);
void GPIO_IRQHandling(uint8_t GPIO_PinNumber);

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F411XE_GPIO_H_ */
