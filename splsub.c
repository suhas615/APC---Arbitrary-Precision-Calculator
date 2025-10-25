/*
Name : S Suhas
Batch - 24030A
Project Name->Arbitary precision Calculator
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "apc.h"

int spcl_case_of_subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *num1, char *num2)
{
    int flag;
    flag_condition(num1, num2, &flag);                          // Determine the sign conditions of num1 and num2

    if (flag == 1)                                              // Both positive numbers
    {
        if (is_greater(num1, num2) == FAILURE)                  // num1 < num2
        {
            digit_to_list(head1, tail1, head2, tail2, num1, num2); // Convert strings to linked lists
            subtraction(head2, tail2, head1, tail1, headR, tailR); // Perform num2 - num1
            cancel_zero(headR, tailR);                              // Remove leading zeros
            print_list(*headR, 1);                                  // Print with negative sign
            return SUCCESS;
        }
        else if (is_greater(num1, num2) == 1)                       // num1 == num2
        {
            printf("\nResult : 0\n");
            return SUCCESS;
        }
        else if (is_greater(num1, num2) == SUCCESS)                    // num1 > num2
        {
            digit_to_list(head1, tail1, head2, tail2, num1, num2);
            subtraction(head1, tail1, head2, tail2, headR, tailR);        // Perform num1 - num2
            cancel_zero(headR, tailR);
            print_list(*headR, 0);                                  // Print positive result
            return SUCCESS;
        }
    }
    else if (flag == 2)                                             // num2 is negative
    {
        int i = 0;
        while (num2[i])                                             // Remove '-' from num2
        {
            num2[i] = num2[i + 1];
            i++;
        }

        
        digit_to_list(head1, tail1, head2, tail2, num1, num2);
        addition(head1, tail1, head2, tail2, headR, tailR);         // All conditions are addition when subtracting negative number
        print_list(*headR, 0);
        return SUCCESS;
    }
    else if (flag == 3)                                             // num1 is negative
    {
        int i = 0;
        while (num1[i])                                             // Remove '-' from num1
        {
            num1[i] = num1[i + 1];
            i++;
        }

        
        digit_to_list(head1, tail1, head2, tail2, num1, num2);
        addition(head1, tail1, head2, tail2, headR, tailR);         // All conditions are addition when subtracting from negative number
        print_list(*headR, 1);                                      // Result will be negative
        return SUCCESS;
    }
    else if (flag == 4)                                             // Both numbers negative
    {
        int i = 0;
        while (num1[i])                                             // Remove '-' from num1
        {
            num1[i] = num1[i + 1];
            i++;
        }
        i = 0;
        while (num2[i])                                              // Remove '-' from num2
        {
            num2[i] = num2[i + 1];
            i++;
        }

        
        if (is_greater(num1, num2) == FAILURE)                          // Subtract num1 - num2 with signs flipped
        {
            digit_to_list(head1, tail1, head2, tail2, num1, num2);
            subtraction(head1, tail1, head2, tail2, headR, tailR);
            cancel_zero(headR, tailR);
            print_list(*headR, 0);                                      // Positive result
            return SUCCESS;
        }
        else if (is_greater(num1, num2) == 1)
        {
            printf("Result is : 0\n");
            return SUCCESS;
        }
        else if (is_greater(num1, num2) == SUCCESS)
        {
            digit_to_list(head1, tail1, head2, tail2, num1, num2);
            subtraction(head1, tail1, head2, tail2, headR, tailR);
            cancel_zero(headR, tailR);
            print_list(*headR, 1);                                         // Negative result
            return SUCCESS;
        }
    }
}