#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c};
uint32_t GetPageStartAddr(uint32_t Address)
{
	uint32_t NbrPage;
	NbrPage = (Address & ~0x08000000) / 0x0800;
	return 0x08000000 + 0x0800 * NbrPage;
}

union test{
	uint8_t wtd[4];
	uint32_t wwtd;
};
int main(int argc, char *argv[])
{
//	union test ttt = {.wtd = "Test"};
	uint8_t wtd[] = "Test";
	uint32_t wwtd = *(uint32_t *)wtd;

	printf("0x%X\n", wwtd);
	return 0;
}
