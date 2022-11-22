#ifndef SHELL_H
#define SHELL_H

void history(char* str);
void history_clear(void);
void history_print(void);
char* history_access(char* str);
void create_alias(char* str);
void list_alias();
char* access_alias(char* str);

#endif