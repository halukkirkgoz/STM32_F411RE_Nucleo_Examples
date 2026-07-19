/*
 * itm_send_data.h
 *
 *  Created on: Jun 9, 2026
 */

#ifndef ITM_SEND_DATA_H_
#define ITM_SEND_DATA_H_

/* Includes */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Debug Exception and Monitor Control Register */
#define DEMCR               (*(volatile uint32_t* const) ((uint32_t) 0xE000EDFCUL))

/* ITM Registers */
#define ITM_STIMULUS_PORT0_U8   (*(volatile uint8_t* const)  ((uint32_t) 0xE0000000UL)) // ITM Stimulus Port 0 Register, 8-bit access
#define ITM_STIMULUS_PORT0_U32  (*(volatile uint32_t* const) ((uint32_t) 0xE0000000UL)) // ITM Stimulus Port 0 Register, 32-bit access
#define ITM_TCR                 (*(volatile uint32_t* const) ((uint32_t) 0xE0000E80UL)) // ITM Trace Control Register
#define ITM_TER                 (*(volatile uint32_t* const) ((uint32_t) 0xE0000E00UL)) // ITM Trace Enable Register

/* Return Values of ITM Functions */
#define ITM_SEND_OK         ((int8_t) 0L)  // Character was successfully written to the ITM stimulus port
#define ITM_SEND_BUSY       ((int8_t) -1L) // ITM stimulus port FIFO is busy or not ready
#define ITM_SEND_DISABLED   ((int8_t) -2L) // ITM, trace block, or stimulus port 0 is not enabled

/* Function Prototypes */
void ITM_Init(void);
int8_t ITM_SendChar_Blocking(uint8_t ch);

#ifdef __cplusplus
}
#endif

#endif /* ITM_SEND_DATA_H_ */
