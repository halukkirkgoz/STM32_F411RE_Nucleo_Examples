#include <stdio.h>

int main(void)
{
	printf("Hello World!\n");

	// Loop forever
	while (1) {
		// Do nothing
		__asm volatile("nop");
	}
}
