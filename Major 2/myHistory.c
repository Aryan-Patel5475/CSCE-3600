#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// array to store history
#define MAX_LEN 512
char history_array[20][MAX_LEN];
int array_counter = 0;

// function for adding user command to the user
void history(char *str) {
    
    //if array_counter < 20 then keep adding onto the stack
    if (array_counter < 20) {
        strcpy(history_array[array_counter], str);
        array_counter += 1;
    }
    // other wise start from the beginning
    else {
        array_counter = 0;
        strcpy(history_array[array_counter], str);
        array_counter += 1;
    }

}

// function for printing the history
void history_print() {
    // looping 20 time and displaying the output of stored command
    for (int i = 0; i < 20; i++) {
        printf("%s\n", history_array[i]);
    }
    
}

// function to clear the history
void history_clear() {
    // looping 20 time and clearing the history
    for (int i = 0; i < 20; i++) {
        strcpy(history_array[i], "0");
    }
    array_counter = 0;
}

// function to access history
char* history_access(char* str) {
    
    char* token = strtok(str, " ");
    
    // temp array to store split words from the user command
    char temp_array[3][MAX_LEN];
    
    int i = 0;
    
    // looping until end of the array is not reached
    while (token != NULL) {
        strcpy(temp_array[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    
    // converting string to int, to access index of stored command
    int num = atoi(temp_array[2]);
    
    // returning stored command
    return history_array[num];    
}
