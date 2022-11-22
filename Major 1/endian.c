#include "major1.h"
#include <stdio.h>
#define B0 0
#define B1 1
#define B2 2
#define B3 3

void endian_swap(void) {
	
	//Variables 
	long long int original_no, swapped_no;
	
	//Ask user to enter a number between a range
	printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
	scanf("%lld", &original_no);
	
	//Check to see if number entered matches the range requested, if not prompt the user again
	while (original_no < 1 || original_no > 4294967295) {
		printf("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ");
		scanf("%lld", &original_no);
	}
	
	//Assign the user value to the swapped variable
	swapped_no = original_no;
	
	//Pointer to break user value into bytes
	char *val = (char*)(&swapped_no); 
	
	//Swap B0 and B3 bytes
	val[B0] = val[B0] ^ val[B3];
	val[B3] = val[B0] ^ val[B3];
	val[B0] = val[B0] ^ val[B3];
	
	//Swap B1 and B2 bytes
	val[B1] = val[B1] ^ val[B2];
	val[B2] = val[B1] ^ val[B2];
	val[B1] = val[B1] ^ val[B2];
	
	//Display original and swapped values
	printf("Endian swap of %lld gives %lld\n", original_no, swapped_no);
}
