#include <stdio.h>
#include <stdlib.h>
#include "../library/authentication.h"

void displayScreen();

int main()
{
  FILE *fptr;
  displayScreen();
  int choice = 0;
  while (choice != 5)
  {
    
    printf("Enter Selection: ");
    scanf("%d", &choice);
    switch (choice)
    {
      case 1: 
        register_user(&fptr);
        break;
      case 2:
        printf("-----\tLOGIN\t-----\n");
        validate(&fptr);
      break;
      case 5:
        break;
    }
  }
  return 0;
}

void displayScreen()
{
  printf("##############################\n");
  printf("#  School Management System  #\n");
  printf("#----------------------------#\n");
  printf("#       1. Register          #\n");
  printf("#       5. Exit              #\n");
  printf("##############################\n");
}