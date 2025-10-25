/*
Name : S Suhas
Batch - 24030A
Project Name->Arbitary precision Calculator
sample input- 200 / 100
sample output- Number 1-> 200 Number 2->100  result= 2
*/
#include <stdio.h>
#include <stddef.h>
#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, long int *data)
{
	int result = 0;

	// Check if dividend or divisor is empty
	if (*head1 == NULL)
	{
		printf("\nINFO: List1 (dividend) is empty\n");
		return FAILURE;
	}

	if (*head2 == NULL)
	{
		printf("\nINFO: List2 (divisor) is empty\n");
		return FAILURE;
	}

	// Repeated subtraction until dividend < divisor
	while (is_larger(head1, tail1, head2, tail2) == SUCCESS)
	{
		subtraction(head1, tail1, head2, tail2, headR, tailR); // head1 = head1 - head2
		delete_list(head1, tail1);						   // Free old dividend list

		*head1 = *headR; // Store updated result back in head1
		*tail1 = *tailR;

		*headR = NULL; // Reset temporary result list
		*tailR = NULL;

		cancel_zero(head1, tail1); // Remove leading zeros

		result++; // Count the number of subtractions = quotient
	}

	*data = result; // Store quotient in output variable
	return SUCCESS;
}