#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "../library/authentication.h"

#define MAXSIZE 50
#define PASSSIZE 20

void register_user(FILE **fptr){
    char email[MAXSIZE];
    char pass[PASSSIZE];
    int c;
    int i = 0;
    printf("ENTER EMAIL: ");
    scanf("%s", email);
    printf("ENTER PASSWORD: ");
    
    while((c = _getch()) != 13)
    {
        if (c == 8){
            i--;
            printf("\b \b");
        }
        else {
            pass[i++] = c;
            printf("*");
        }
    }
    pass[i] = '\0';
    printf("\n");
    *fptr = fopen(".secret/.auth.txt", "a");
    fprintf(*fptr, "%s ", email);
    fprintf(*fptr, "%s\n", pass);
    fclose(*fptr);
}

void validate(FILE **fptr){
    char email[MAXSIZE], check_email[MAXSIZE], pass[PASSSIZE], check_pass[PASSSIZE];
    int i = 0;
    int boolean = 0;
    printf("EMAIL: ");
    scanf("%s", email);
    *fptr = fopen(".secret/.auth.txt", "r");
    if(!(*fptr)){
        printf("Could not open file. ERROR... \n");
    }
    while (1)
    {
        char c = fgetc(*fptr);
        if (c == ' ' || c == '\n'){ // checks if is a character
            if (strcmp(check_email, email) == 0)
                boolean = 1;
        
            for (int index = 0; index < i; index++)
                check_email[index] = '\0';
            i = 0; // resets check_email to beginning of array
        }
        else{
            check_email[i++] = c; // inputs character read from file at current pointer
        }
        if (feof(*fptr))
            break;
    }

    fclose(*fptr);
    if (boolean)
        printf("registered..\n");
    else
        printf("not registered..\n");
}