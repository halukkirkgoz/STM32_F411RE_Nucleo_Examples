/*
 * stm32f411xe_gpio.c
 *
 *  Created on: Jun 16, 2026
 */

/* Includes */
#include "stm32f411xe_gpio.h"

void GPIO_Init(GPIO_Handle_t *GPIOHandle)
{
	// Configure the mode of the GPIO pin
	uint32_t temp = 0;
	if (GPIOHandle->GPIOx_PinConfig.GPIO_PinMode <= 3) {
		temp = (GPIOHandle->GPIOx_PinConfig.GPIO_PinMode << (GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber * 2));
		GPIOHandle->GPIOx->MODER &= ~(0x3UL << (GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber * 2));
		GPIOHandle->GPIOx->MODER |= temp;
	} else {
		GPIOHandle->GPIOx->MODER &= ~(0x3UL << (GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber * 2));

		if (GPIOHandle->GPIOx_PinConfig.GPIO_PinMode == GPIO_MODE_INPUT_FE) {
			EXTI->FTSR |= (0x1UL << GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber);
			EXTI->RTSR &= ~(0x1UL << GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber);
		} else if (GPIOHandle->GPIOx_PinConfig.GPIO_PinMode == GPIO_MODE_INPUT_RE) {
			EXTI->RTSR |= (0x1UL << GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber);
			EXTI->FTSR &= ~(0x1UL << GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber);
		} else if (GPIOHandle->GPIOx_PinConfig.GPIO_PinMode == GPIO_MODE_INPUT_FERE) {
			EXTI->FTSR |= (0x1UL << GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber);
			EXTI->RTSR |= (0x1UL << GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber);
		}

		uint8_t EXTIRegPosIndex = GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber % 4;
		uint8_t EXTIRegIndex = GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber / 4;
		uint8_t PortCode = (uint8_t) GPIO_BASEADDR_TO_CODE(GPIOHandle->GPIOx);

		RCC->APB2ENR |= (0x1UL << 14);
		SYSCFG->EXTICR[EXTIRegIndex] &= ~(0xFUL << (EXTIRegPosIndex * 4));
		SYSCFG->EXTICR[EXTIRegIndex] |= (PortCode << (EXTIRegPosIndex * 4));

		EXTI->IMR |= (0x1UL << GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber);
	}

	// Configure the output type
	temp = 0;
	if ((GPIOHandle->GPIOx_PinConfig.GPIO_PinMode == GPIO_MODE_OUTPUT)
	        || (GPIOHandle->GPIOx_PinConfig.GPIO_PinMode == GPIO_MODE_ALTERNATE)) {
		temp = (GPIOHandle->GPIOx_PinConfig.GPIO_PinOutputType << GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber);
		GPIOHandle->GPIOx->OTYPER &= ~(0x1UL << GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber);
		GPIOHandle->GPIOx->OTYPER |= temp;
	}

	// Configure the output speed
	temp = 0;
	if ((GPIOHandle->GPIOx_PinConfig.GPIO_PinMode == GPIO_MODE_OUTPUT)
	        || (GPIOHandle->GPIOx_PinConfig.GPIO_PinMode == GPIO_MODE_ALTERNATE)) {
		temp = (GPIOHandle->GPIOx_PinConfig.GPIO_PinOutputSpeed << (GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber * 2));
		GPIOHandle->GPIOx->OSPEEDR &= ~(0x3UL << (GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber * 2));
		GPIOHandle->GPIOx->OSPEEDR |= temp;
	}

	// Configure the pull-up / pull-down setting
	temp = 0;
	temp = (GPIOHandle->GPIOx_PinConfig.GPIO_PinPUPD << (GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber * 2));
	GPIOHandle->GPIOx->PUPDR &= ~(0x3UL << (GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber * 2));
	GPIOHandle->GPIOx->PUPDR |= temp;

	// Configure the alternate function settings
	temp = 0;
	if (GPIOHandle->GPIOx_PinConfig.GPIO_PinMode == GPIO_MODE_ALTERNATE) {
		if (GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber < 8) {
			temp = (GPIOHandle->GPIOx_PinConfig.GPIO_PinAltFunc << (GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber * 4));
			GPIOHandle->GPIOx->AFR[0] &= ~(0xFUL << (GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber * 4));
			GPIOHandle->GPIOx->AFR[0] |= temp;
		} else {
			uint8_t pinPos = GPIOHandle->GPIOx_PinConfig.GPIO_PinNumber % 8;
			temp = (GPIOHandle->GPIOx_PinConfig.GPIO_PinAltFunc << (pinPos * 4));
			GPIOHandle->GPIOx->AFR[1] &= ~(0xFUL << (pinPos * 4));
			GPIOHandle->GPIOx->AFR[1] |= temp;
		}
	}
}

void GPIO_DeInit(GPIO_RegDef_t *GPIOx)
{
	if (GPIOx == GPIOA) {
		RCC->AHB1RSTR |= (0x1UL << 0);
		RCC->AHB1RSTR &= ~(0x1UL << 0);
	} else if (GPIOx == GPIOB) {
		RCC->AHB1RSTR |= (0x1UL << 1);
		RCC->AHB1RSTR &= ~(0x1UL << 1);
	} else if (GPIOx == GPIOC) {
		RCC->AHB1RSTR |= (0x1UL << 2);
		RCC->AHB1RSTR &= ~(0x1UL << 2);
	} else if (GPIOx == GPIOD) {
		RCC->AHB1RSTR |= (0x1UL << 3);
		RCC->AHB1RSTR &= ~(0x1UL << 3);
	} else if (GPIOx == GPIOE) {
		RCC->AHB1RSTR |= (0x1UL << 4);
		RCC->AHB1RSTR &= ~(0x1UL << 4);
	} else if (GPIOx == GPIOH) {
		RCC->AHB1RSTR |= (0x1UL << 7);
		RCC->AHB1RSTR &= ~(0x1UL << 7);
	}
}

void GPIO_ClockControl(GPIO_RegDef_t *GPIOx, uint8_t EnOrDis)
{
	if (EnOrDis == ENABLE) {
		if (GPIOx == GPIOA) {
			RCC->AHB1ENR |= (0x1UL << 0);
		} else if (GPIOx == GPIOB) {
			RCC->AHB1ENR |= (0x1UL << 1);
		} else if (GPIOx == GPIOC) {
			RCC->AHB1ENR |= (0x1UL << 2);
		} else if (GPIOx == GPIOD) {
			RCC->AHB1ENR |= (0x1UL << 3);
		} else if (GPIOx == GPIOE) {
			RCC->AHB1ENR |= (0x1UL << 4);
		} else if (GPIOx == GPIOH) {
			RCC->AHB1ENR |= (0x1UL << 7);
		}
	} else {
		if (GPIOx == GPIOA) {
			RCC->AHB1ENR &= ~(0x1UL << 0);
		} else if (GPIOx == GPIOB) {
			RCC->AHB1ENR &= ~(0x1UL << 1);
		} else if (GPIOx == GPIOC) {
			RCC->AHB1ENR &= ~(0x1UL << 2);
		} else if (GPIOx == GPIOD) {
			RCC->AHB1ENR &= ~(0x1UL << 3);
		} else if (GPIOx == GPIOE) {
			RCC->AHB1ENR &= ~(0x1UL << 4);
		} else if (GPIOx == GPIOH) {
			RCC->AHB1ENR &= ~(0x1UL << 7);
		}
	}
}

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_PinNumber)
{
	uint8_t value = ((uint8_t) ((GPIOx->IDR >> GPIO_PinNumber) & 0x1UL));
	return value;
}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *GPIOx)
{
	uint16_t value = ((uint16_t) (GPIOx->IDR & 0xFFFFUL));
	return value;
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_PinNumber, uint8_t GPIO_OutputValue)
{
	if (GPIO_OutputValue == GPIO_SET) {
		GPIOx->ODR |= (0x1UL << GPIO_PinNumber);
	} else {
		GPIOx->ODR &= ~(0x1UL << GPIO_PinNumber);
	}
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *GPIOx, uint16_t GPIO_OutputValue)
{
	GPIOx->ODR &= ~(0xFFFFUL);
	GPIOx->ODR = (uint32_t) GPIO_OutputValue;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *GPIOx, uint8_t GPIO_PinNumber)
{
	GPIOx->ODR ^= (0x1UL << GPIO_PinNumber);
}

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnOrDis)
{
	uint8_t RegIndex = IRQNumber / 32;
	uint8_t PosIndex = IRQNumber % 32;

	if (EnOrDis == ENABLE) {
		switch (RegIndex) {
		case 0:
			NVIC_ISER0 |= (0x1UL << PosIndex);
			break;
		case 1:
			NVIC_ISER1 |= (0x1UL << PosIndex);
			break;
		case 2:
			NVIC_ISER2 |= (0x1UL << PosIndex);
			break;
		}
	} else {
		switch (RegIndex) {
		case 0:
			NVIC_ICER0 |= (0x1UL << PosIndex);
			break;
		case 1:
			NVIC_ICER1 |= (0x1UL << PosIndex);
			break;
		case 2:
			NVIC_ICER2 |= (0x1UL << PosIndex);
			break;
		}
	}
}

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority)
{
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section = IRQNumber % 4;
	uint8_t shift_amount = (uint8_t) ((iprx_section * 8) + (8 - 4)); // Since 4 upper bits of interrupt priority are used

	*(NVIC_IPR_BASE_ADDR + iprx) &= ~(0xFFUL << (iprx_section * 8));
	*(NVIC_IPR_BASE_ADDR + iprx) |= ((uint32_t) IRQPriority << shift_amount);
}

void GPIO_IRQHandling(uint8_t GPIO_PinNumber)
{
	if (EXTI->PR & (0x1UL << GPIO_PinNumber)) {
		EXTI->PR |= (0x1UL << GPIO_PinNumber);
	}
}
