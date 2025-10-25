/*
Name : S Suhas
Batch - 24030A
Project Name->Arbitary precision Calculator
sample input- 100 + 200
sample output- Number 1-> 100 Number 2->200  Addition of Numbers= 300
*/
#include <stddef.h>
#include <stdio.h>
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	
	if (*head1 == NULL || *head2 == NULL)						// Return failure if either of the input numbers is not provided
	{
		return FAILURE;
	}

	Dlist *temp1 = *tail1; 										
	Dlist *temp2 = *tail2; 										
	int sum, data, carry = 0;
	int num1, num2;

	while (temp1 != NULL || temp2 != NULL)						// Traverse both numbers from LSB to MSB
	{
		num1 = 0;
		num2 = 0;

		
		if (temp1 != NULL)										// Extract digit from number 1 if present
		{
			num1 = temp1->data;
		}

		
		if (temp2 != NULL)										// Extract digit from number 2 if present
		{
			num2 = temp2->data;
		}

		
		sum = num1 + num2 + carry;								// Calculate sum of digits and carry
		data = sum % 10;					 					// Result digit
		insert_first(headR, tailR, data); 						// Insert result digit at head
		carry = sum / 10;					 					// Update carry

		
		if (temp1 != NULL)										// Move to next higher digit in number 1
		{
			temp1 = temp1->prev;
		}

		
		if (temp2 != NULL)										// Move to next higher digit in number 2
		{
			temp2 = temp2->prev;
		}
	}

	
	if (carry != 0)												// Insert remaining carry, if any
	{
		insert_first(headR, tailR, carry);
	}

	return SUCCESS;
}