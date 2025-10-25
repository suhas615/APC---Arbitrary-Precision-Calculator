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

int spcl_cases_of_addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *num1, char *num2)
{
    int flag;
    flag_condition(num1, num2, &flag);                          // to determine the sign condition between num1 and num2

    if (flag == 1)                                              // Case: If both numbers are positive
    {
        digit_to_list(head1, tail1, head2, tail2, num1, num2);  // Convert strings to digit-wise linked lists
        addition(head1, tail1, head2, tail2, headR, tailR);     // Perform addition
        print_list(*headR, 0);                                  // Print the result
        return SUCCESS;
    }
    else if (flag == 2)                                         // Case: if num1 is positive, num2 is negative
    {
        int i = 0;
        while (num2[i])
            num2[i] = num2[i + 1], i++;                         // Remove '-' sign from num2

        if (is_greater(num1, num2) == SUCCESS)                  // num1 > num2
        {
            digit_to_list(head1, tail1, head2, tail2, num1, num2);
            subtraction(head1, tail1, head2, tail2, headR, tailR);
            print_list(*headR, 0);                              // Result is positive
            return SUCCESS;
        }
        else if (is_greater(num1, num2) == FAILURE)             // num1 < num2
        {
            digit_to_list(head1, tail1, head2, tail2, num1, num2);
            subtraction(head2, tail2, head1, tail1, headR, tailR);
            print_list(*headR, 1);                              // Result is negative
            return SUCCESS;
        }
        else if (is_greater(num1, num2) == 1)                   // num1 == num2
        {
            printf("\nResult : 0\n");                           // Result is zero
            return SUCCESS;
        }
    }
    else if (flag == 3)                                         // Case: if num1 is negative, num2 is positive
    {
        int i = 0;
        while (num1[i])
            num1[i] = num1[i + 1], i++;                         // Remove '-' sign from num1

        if (is_greater(num1, num2) == SUCCESS)                  // num1 > num2
        {
            digit_to_list(head1, tail1, head2, tail2, num1, num2);
            subtraction(head1, tail1, head2, tail2, headR, tailR);
            cancel_zero(headR, tailR);                          // Remove unnecessary leading zeroes
            print_list(*headR, 1);                              // Result is negative
            return SUCCESS;
        }
        else if (is_greater(num1, num2) == FAILURE)             // num1 < num2
        {
            digit_to_list(head1, tail1, head2, tail2, num1, num2);
            subtraction(head2, tail2, head1, tail1, headR, tailR);
            print_list(*headR, 0);                              // Result is positive
            return SUCCESS;
        }
        else if (is_greater(num1, num2) == 1)                   // num1 == num2
        {
            printf("\nResult : 0\n");
            return SUCCESS;
        }
    }
    else if (flag == 4)                                         // Case: if both numbers are negative
    {
        int i = 0;
        while (num1[i])
            num1[i] = num1[i + 1], i++;                         // Remove '-' from num1
        i = 0;
        while (num2[i])
            num2[i] = num2[i + 1], i++;                         // Remove '-' from num2

        digit_to_list(head1, tail1, head2, tail2, num1, num2);
        addition(head1, tail1, head2, tail2, headR, tailR);      // Add absolute values
        print_list(*headR, 1);                                    // Result is negative
        return SUCCESS;
    }

    return FAILURE;                             
}