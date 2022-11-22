#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 512
// array for storing new alias and what they mean, limit of 100
char new_alias[100][MAX_LEN];
char old_alias[100][MAX_LEN];
int num = 0;

// function to create new aliases
void create_alias(char* str) {
	
	char* token = strtok(str, " ");
	
	// temp array to store split words from user input
	char temp_array[3][MAX_LEN];
	
	int i = 0;
	while (token != NULL) {
		strcpy(temp_array[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	
	// storing the second word and third word into the corresponding array
	strcpy(new_alias[num], temp_array[1]);
	strcpy(old_alias[num], temp_array[2]);
	num++;
	printf("alias created\n");
}

// function to print the list of all the alias created and there original meaning
void list_alias() {
	printf("new alias old alias\n");
	for (int i = (num - 1); i != -1; i--) {
		printf("    %s       %s\n", new_alias[i], old_alias[i]);
	}
}


// function to access the alias
char* access_alias(char* str) {
	char* token = strtok(str, " ");
	
	char temp_array[2][MAX_LEN];
	
	int i = 0;
	
	while (token != NULL) {
		strcpy(temp_array[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	
	int j = 0;
	
	// looping 100 times
	while (j < 100) {
		
		int k = strcmp(temp_array[1], new_alias[j]);
		
		// if we found the alias then stopping the loop
		if (k == 0) {
			break;
		}
		else {
			j+= 1;
		}
	}
	
	// and returning the meaning of alias to the prompt
	return old_alias[j];
}