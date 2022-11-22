#include "major1.h"
#include <stdio.h>

void leading_zeroes(void) {
	
	// declaring Size of int in an constant variable
	const int INT_SIZE = sizeof(int) * 8;
	
	long long int num = -1;
	int i = INT_SIZE - 1, leading_zeroes = 0;
	int binary[INT_SIZE];
	
	// asking and taking in user input until he enters eligible numbers
	while (num < 1 || num > 4294967295) {
		printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): "); scanf("%lld", &num);
	}
	
	// creating variable to store user input
	long long int original_num = num;
	
	// maniuplating bit until we fill all the array
	while (i >= 0) {
		binary[i] = num & 1;
		num >>= 1;
		--i;
	}
	
	// using loop to count number of leading zeroes
	for (int j = 0; j < INT_SIZE; ++j) {
		if (binary[j] != 0) {
			break;				// terminating loop
		} else {
			++leading_zeroes;
		}
	}
	
	// Outputing the final result
	printf("The number of leading zeroes in %lld is %d\n\n", original_num, leading_zeroes);
}
