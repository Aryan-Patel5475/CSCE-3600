// Name: Aryan Patel
// EUID: asp0144

#include <stdio.h>

int main() {
	
	char chr;
	int binary[8];
	
	printf("Enter an ASCII character: ");
	scanf("%c", &chr);

	
	int dec = chr;
	
	printf("         dec -- %d\n", chr);
	printf("         hex -- %x\n", chr);
	
	int i = 7;
	
	while (i >= 0) {
		binary[i] = dec & 1;
		printf("dec: %d\n", dec);
		i--;
		dec >>= 1;
	}
	
	printf("         bin -- ");
	for (int j = 0; j < 8; ++j)
		printf("%d", binary[j]);
	printf("\n");
	
	return 0;
}
