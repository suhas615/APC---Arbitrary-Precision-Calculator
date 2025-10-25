/*
Name : S Suhas
Batch - 24030A
Project Name->Arbitary precision Calculator
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "apc.h"

int spcl_case_of_multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, Dlist **headR1, Dlist **tailR1, Dlist **headR2, Dlist **tailR2, char *num1, char *num2)
{
    int flag;
    flag_condition(num1, num2, &flag);                      // Determine the sign configuration of the numbers

    if (flag == 1)                                          // Both numbers are positive
    {
        digit_to_list(head1, tail1, head2, tail2, num1, num2); // Convert digits to list
        multiplication(head1, tail1, head2, tail2, headR, tailR, headR1, tailR1, headR2, tailR2);
        print_list(*headR2, 0);                                 // Print final result with positive sign
        return SUCCESS;
    }
    else if (flag == 2)                                         // num2 is negative
    {
       
        int i = 0;                                               // Remove minus sign from num2
        while (num2[i])
        {
            num2[i] = num2[i + 1];
            i++;
        }
        digit_to_list(head1, tail1, head2, tail2, num1, num2);
        multiplication(head1, tail1, head2, tail2, headR, tailR, headR1, tailR1, headR2, tailR2);
        print_list(*headR2, 1);                                 // Result is negative
        return SUCCESS;
    }
    else if (flag == 3)                                         // num1 is negative
    {
        
        int i = 0;                                              // Remove minus sign from num1
        while (num1[i])
        {
            num1[i] = num1[i + 1];
            i++;
        }
        digit_to_list(head1, tail1, head2, tail2, num1, num2);
        multiplication(head1, tail1, head2, tail2, headR, tailR, headR1, tailR1, headR2, tailR2);
        print_list(*headR2, 1); // Result is negative
        return SUCCESS;
    }
    else if (flag == 4)                                         // Both numbers are negative
    {
        
        int i = 0;                                               // Remove minus signs from both
        while (num1[i])
        {
            num1[i] = num1[i + 1];
            i++;
        }
        i = 0;
        while (num2[i])
        {
            num2[i] = num2[i + 1];
            i++;
        }
        digit_to_list(head1, tail1, head2, tail2, num1, num2);
        multiplication(head1, tail1, head2, tail2, headR, tailR, headR1, tailR1, headR2, tailR2);
        print_list(*headR2, 0);                                            // Result is positive
        return SUCCESS;
    }
}