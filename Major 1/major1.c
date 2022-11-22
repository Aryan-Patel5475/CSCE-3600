#include "major1.h"
#include <stdio.h>

void menu() {
	printf("Enter the menu option for the operation to perform:\n");
	printf("(1) Count Leading Zeroes\n");
	printf("(2) Endian Swap\n");
	printf("(3) Rotate-right\n");
	printf("(4) Parity\n");
	printf("(5) EXIT\n");
}

int main() {
	
	int user_choise = -1;
	
	while ( user_choise != 5) {
		menu();
		printf("--> "); scanf("%d", &user_choise);
		
		while (user_choise < 1 || user_choise > 5) {
			printf("Error: Invalid option. Please try again.\n");
			menu();
			printf("--> "); scanf("%d", &user_choise);
		}

		if (user_choise == 1)
			leading_zeroes();
		else if (user_choise == 2)
			endian_swap();
		else if (user_choise == 3)
			rotate_num();
		else if (user_choise == 4)
			parity_num();
		else if (user_choise == 5)
			printf("Program terminating. Goodbye...\n");
	}
	
	return 0;
}
