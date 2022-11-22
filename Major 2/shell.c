#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <menu.h>

// defining maximing number of character inputed by user
#define MAX_LEN 512

// declaring function
void menu();
void interactive_mod();
void bash_mode();
int checkWord(char* str1, char* wrd);

int main() {
    
    menu();         // printing menu
    int user_choice;
    
    printf("Enter: ");  // asking for user input
    scanf(" %d", &user_choice);
    printf("\n");
    
    // if user enter 1 open it in interactive mod else bash mod
    if (user_choice == 1) {
        interactive_mod();
    }
    else {
        bash_mode();
    }
    
    return 0;
}

// menu function
void menu() {
    printf("---------------------\n");
    printf("| 1. Interative mod |\n");
    printf("| 2. Bash mod       |\n");
    printf("---------------------\n");
}

// interactive mod function
void interactive_mod() {
    history_clear();
    
    // infinite loop until user enters exit
    while (1) {
        char user_input[MAX_LEN];
        
        // asking for user command
        printf("Prompt > ");
        scanf(" %511[^\n]", user_input);
        
        // if command has history then don't store it in history
        int history_check = checkWord(user_input, "history");
        if (history_check != 1) {
            history(user_input);
        }
        
        // if command has -c then call the history clear function
        int i = checkWord(user_input, "-c");
        if (i == 1) {
            history_clear();
        }
        
        // if command -p then call the print function
        i = checkWord(user_input, "-p");
        if (i == 1) {
            history_print();
        }
        
        // if user enters exit then exit the program
        int k = checkWord(user_input, "exit");
        if (k == 1) {
            exit(0);
        }
        
        // if user enter -e then call history access function
        int acces_num = checkWord(user_input, "-e");
        if (acces_num == 1) {
            strcpy(user_input, history_access(user_input));
            printf("retrieved from history\n");
            printf("Prompt > %s\n", user_input);
        }
        
        // if there is alias in command then create new alias by calling function
        int create_num = checkWord(user_input, "alias");
        if (create_num == 1) {
            create_alias(user_input);
        }
        
        // if there is access in command then call access function
        int accessNum = checkWord(user_input, "access");
        if (accessNum == 1) {
            strcpy(user_input, access_alias(user_input));
            printf("Prompt > %s\n", user_input);
        }
        
        // if there is list in command then print out all the alias created
        int print_alias = checkWord(user_input, "list");
        if (print_alias == 1) {
            list_alias();
        }
        
    }
    
}

// function for bash mod
void bash_mode() {
    
    FILE* ptr;
    
    // opening the file
    ptr = fopen("batch_test.txt", "r");
    
    // dispaly error if failed to open file
    if (NULL == ptr) {
        printf("batch_test.txt can't be opened\n");
    }
    
    char user_input[MAX_LEN];
    
    // looping until the end of the file
    while(fgets(user_input, sizeof(user_input), ptr) != NULL) {
        //fputs(user_input, stdout);
        user_input[strlen(user_input)-1] = '\0';
        printf("Prompt > %s\n", user_input);
        
        int history_check = checkWord(user_input, "history");
        if (history_check != 1) {
            history(user_input);
        }
        
        int i = checkWord(user_input, "-c");
        if (i == 1) {
            history_clear();
        }
        
        i = checkWord(user_input, "-p");
        if (i == 1) {
            history_print();
        }
        
        int k = checkWord(user_input, "exit");
        if (k == 1) {
            exit(0);
        }
        
        int acces_num = checkWord(user_input, "-e");
        if (acces_num == 1) {
            strcpy(user_input, history_access(user_input));
            printf("retrieved from history\n");
            printf("Prompt > %s\n", user_input);
        }
        
        int create_num = checkWord(user_input, "alias");
        if (create_num == 1) {
            create_alias(user_input);
        }
        
        int accessNum = checkWord(user_input, "access");
        if (accessNum == 1) {
            strcpy(user_input, access_alias(user_input));
            printf("Prompt > %s\n", user_input);
        }
        
        int print_alias = checkWord(user_input, "list");
        if (print_alias == 1) {
            list_alias();
        }
    }
    
    fclose(ptr);
    
}

// function to see if a particular word is present in a sentence
int checkWord(char* str1, char* wrd) {
    char* ret;
    
    ret = strstr(str1, wrd);
    if (ret) {
        int i = 1;
        return i;
    }
    else {
        int i = 0;
        return i;
    }
}
