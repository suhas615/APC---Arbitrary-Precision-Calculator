// Name : S Suhas
// Batch - 24030A
// Project Name->Arbitary precision Calculator
// sample input- 100 - 50
// sample output- Number 1-> 100 Number 2->50  Subtraction of Numbers= 50

#include <stddef.h>
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	
	if (*head1 == NULL || *head2 == NULL)									// Return failure if either input list is empty
	{
		return FAILURE;
	}

	Dlist *temp1 = *tail1; 												// Point to least significant digit of first number
	Dlist *temp2 = *tail2; 												// Point to least significant digit of second number
	int num1, num2, borrow = 0, res, data;

	
	while (temp1 != NULL || temp2 != NULL)								// Loop until both number digits are processed
	{
		num1 = 0;
		num2 = 0;

		
		if (temp1 != NULL)												// Fetch digit from first number if available
		{
			num1 = temp1->data;
		}

		
		if (temp2 != NULL)												// Fetch digit from second number if available
		{
			num2 = temp2->data;
		}

		num1 = num1 - borrow; 											// Apply previous borrow if any

		
		if (num1 < num2)												// Check if borrow is needed
		{
			borrow = 1; 												// Borrow needed for next higher digit
		}
		else
		{
			borrow = 0; 
		}

		
		res = num1 + (borrow * 10) - num2;

		
		if (insert_first(headR, tailR, res) == FAILURE)				// Insert result digit at front of result list
		{
			return FAILURE;
		}

		
		if (temp1 != NULL)												// Move to next higher digit
		{
			temp1 = temp1->prev;
		}
		if (temp2 != NULL)
		{
			temp2 = temp2->prev;
		}
	}

	return SUCCESS; // Return success after subtraction completes
}
