/*
Name : S Suhas
Batch - 24030A
Project Name->Arbitary precision Calculator
sample input- 100 x 200
sample output- Number 1-> 100 Number 2->200  product of Numbers= 20000
*/




#include <stddef.h>
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, Dlist **headR1, Dlist **tailR1, Dlist **headR2, Dlist **tailR2)
{
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int num1, num2, prod, data, carry = 0, count = 0;

	
	while (temp1 != NULL)							// Outer loop for each digit in first number (starting from least significant digit)
	{
		carry = 0;
		num1 = temp1->data;

		
		while (temp2 != NULL)   					// Inner loop for each digit in second number
		{
			num2 = temp2->data;
			prod = (num1 * num2) + carry;		   // Multiply digits and add carry
			data = prod % 10;					   // Extract single digit
			carry = prod / 10;					   // Update carry
			insert_first(headR1, tailR1, data); // Store partial result in reverse
			temp2 = temp2->prev;
		}

		if (carry != 0)								// Insert final carry if any
		{
			insert_first(headR1, tailR1, carry);
        }
		
		for (int i = 0; i < count; i++)				// Add trailing zeros (like shifting left in manual multiplication)
		{
			insert_last(headR1, tailR1, 0);
		}

		
		if (*headR2 == NULL)						// If this is the first iteration, initialize headR2
		{
			insert_first(headR2, tailR2, 0);
		}

		addition(headR1, tailR1, headR2, tailR2, headR, tailR); // Add current partial product to the accumulated result
		delete_list(headR2, tailR2);			// Clear R2 and R1 for next iteration
		delete_list(headR1, tailR1);

		*headR2 = *headR;						// Move current result to R2 (acts as cumulative total)
		*tailR2 = *tailR;
		
		*headR = NULL;							// Reset headR and tailR for next use
		*tailR = NULL;

		temp1 = temp1->prev; 					// Move to next digit of first number
		count++;			 					// Increment shift count
		temp2 = *tail2;		 					// Reset second number pointer
	}

	return SUCCESS;
}