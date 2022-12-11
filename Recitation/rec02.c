// Name: Aryan Patel
// EUID: asp0144

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int *ptr;
	ptr = (int*)malloc(2 * sizeof(int));
	
	if (ptr == NULL) {
		printf("Failed to allocate memory\n");
		return 1;
	}
	
	printf("Enter the value for the first element: "); scanf("%d", &ptr[0]);
	printf("Enter the value for the second element: "); scanf("%d", &ptr[1]);
	
	printf("Original values 1st = %d, 2nd = %d\n", ptr[0], ptr[1]);
	
	ptr[0] = ptr[0] ^ ptr[1];
	ptr[1] = ptr[1] ^ ptr[0];
	ptr[0] = ptr[0] ^ ptr[1];
	
	printf("Swapped values 1st = %d, 2nd = %d\n", ptr[0], ptr[1]);
	
	free(ptr);
	
	return 0;
}