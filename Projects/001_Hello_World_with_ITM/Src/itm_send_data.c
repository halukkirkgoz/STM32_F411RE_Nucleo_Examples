/*
 * itm_send_data.c
 *
 *  Created on: Jun 9, 2026
 */

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Implementation of printf-like feature using ARM Cortex-M3/M4/M7 ITM (Instrumentation Trace Macrocell)
//  This function WILL NOT work for ARM Cortex-M0/M0+ as they lack the ITM hardware component.
//  For Cortex-M0/M0+, you can use the OpenOCD/GDB Semihosting feature or UART for debugging.
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdint.h>
#include "itm_send_data.h"

void ITM_Init(void)
{
	// Enable TRCENA (Bit 24) in DEMCR to power up the Trace block components (ITM, DWT, etc.)
	DEMCR |= (0x1UL << 24);

	// Enable ITM globally by setting ITMENA (Bit 0) in ITM_TCR
	ITM_TCR |= (0x1UL << 0);

	// Enable ITM Stimulus Port 0 by setting Bit 0 in ITM_TER
	ITM_TER |= (0x1UL << 0);
}

int8_t ITM_SendChar_Blocking(uint8_t ch)
{
	// Check whether the trace block is enabled by verifying TRCENA (Bit 24) in DEMCR
	if ((DEMCR & (0x1UL << 24)) == 0U) {
		return ITM_SEND_DISABLED;
	}

	// Check whether ITM is globally enabled by verifying ITMENA (Bit 0) in ITM_TCR
	if ((ITM_TCR & (0x1UL << 0)) == 0U) {
		return ITM_SEND_DISABLED;
	}

	// Check whether ITM Stimulus Port 0 is enabled by verifying Bit 0 in ITM_TE
	if ((ITM_TER & (0x1UL << 0)) == 0U) {
		return ITM_SEND_DISABLED;
	}

	// Wait until the ITM Stimulus Port 0 FIFO is ready to accept new data
	// Reading the stimulus port returns 1 if the FIFO is ready (not full)
	while ((ITM_STIMULUS_PORT0_U32 & 0x1UL) == 0) {
		// Do nothing, wait for FIFO to clear
	}

	// Write the character to ITM Stimulus Port 0
	ITM_STIMULUS_PORT0_U8 = ch;

	// Return success after the character has been written
	return ITM_SEND_OK;
}

/*
 * Here is the step-by-step guide to configuring and opening the ITM console in STM32CubeIDE:
 * Step 1: Before configuring the IDE, make sure your code actually routes printf to the ITM stimulus port by modifying _write function.
 *
 * Step 2: Ensure you are using SWD (Serial Wire Debug) mode, not JTAG and configure debug settings in STM32CubeIDE.
 *       - In STM32CubeIDE, click the arrow next to the Debug icon (the bug) and select Debug Configurations...
 *       - Select your project configuration under STM32 Cortex-M C/C++ Application.
 *       - Switch to the Debugger tab.
 *       - Ensure the debug probe is set to ST-LINK (ST-LINK GDB server).
 *       - Ensure the interface is set to SWD.
 *       - Scroll down and make sure Serial Wire Viewer (SWV) is enabled by checking the Enable box.
 *       - Core Clock (MHz): Type the exact frequency your STM32 CPU is running at in MHz (e.g., 16.0 for 16MHz, 168.0 for 168MHz).
 *         If this frequency is wrong, you will see garbled text or nothing at all.
 *       - Click Apply and then Debug to start the debugging session.
 *
 * Step 3: Once the IDE enters the Debug perspective (the code is paused at main or SystemInit):
 *       - Go to the top menu bar: Window ➔ Show View ➔ SWV ➔ SWV ITM Data Console.
 *       - A new tab named SWV ITM Data Console will appear at the bottom of your screen.
 *       - Click the Configure trace icon (the small wrench icon) in the top-right toolbar of that specific ITM console window.
 *       - In the configuration window:
 *         - Under ITM Stimulus Ports, check the box for Port 0 (this matches the port we used in our code).
 *         - Leave everything else as default and click OK.
 * Step 4: Look at the toolbar of the SWV ITM Data Console tab:
 *       - Click the red Start Trace button (the red circle icon). This tells the IDE to start listening to the SWO pin.
 *       - Now, press Resume (F8) (the green play button) to run your STM32 code. You will see your printf messages appearing live inside the ITM console.
 */
