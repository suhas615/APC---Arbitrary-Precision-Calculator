/*
Name : S Suhas
Batch - 24030A
Project Name->Arbitary precision Calculator
*/
#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

int main(int argc, char *argv[])
{
	
	if (read_and_validation(argc, argv) == FAILURE)							// Check if the number of command-line arguments is correct
	{
		printf("\nINFO : Command line argument should have length 4\n");
		return SUCCESS;
	}

	
	Dlist *head1 = NULL, *tail1 = NULL;										// Initialize all the required doubly linked list pointers
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL, *tailR = NULL;			  							// Result list
	Dlist *headR1 = NULL, *tailR1 = NULL;		  							// Extra result list 1 (used in multiplication)
	Dlist *headR2 = NULL, *tailR2 = NULL;		  							// Extra result list 2 (used in multiplication)
	Dlist *headbackup = NULL, *tailbackup = NULL; 							// Unused here, maybe for future use

	
	char operator= argv[2][0];
	int data = 0, res, flag;

	
	switch (operator)
	{
	case '+':
		// Call addition function
		spcl_cases_of_addition(&head1, &tail1, &head2, &tail2, &headR, &tailR, argv[1], argv[3]);
		break;

	case '-':
		// Call subtraction function
		spcl_case_of_subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR, argv[1], argv[3]);
		break;

	case 'x':
		// Call multiplication handler function
		spcl_case_of_multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR,&headR1, &tailR1, &headR2, &tailR2, argv[1], argv[3]);
		break;

	case '/':
		// Call division handler function
		spcl_case_of_division(&head1, &tail1, &head2, &tail2, &headR, &tailR, argv[1], argv[3]);
		break;

	default:
		// Handle invalid operator input
		printf("Invalid Input:-( Try again...\n");
	}

	return 0;
}