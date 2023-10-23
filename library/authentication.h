#ifndef AUTH_H
#define AUTH_H
#include <stdio.h>
/* will register user */
void register_user(FILE **fptr);

/* checks if user is registered */
void validate(FILE **fptr);

#endif