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

int spcl_case_of_division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *num1, char *num2)
{
    int flag;
    long int result;
    flag_condition(num1, num2, &flag);

    // Handle division by zero
    if (strcmp(num2, "0") == 0 || strcmp(num2, "-0") == 0)
    {
        printf("Error: Division by zero is undefined.\n");
        return FAILURE;
    }

    // Remove minus signs based on flag
    if (flag == 2 || flag == 4)
        memmove(num2, num2 + 1, strlen(num2));
    if (flag == 3 || flag == 4)
        memmove(num1, num1 + 1, strlen(num1));

    int cmp = is_greater(num1, num2);

    if (cmp == FAILURE) // num1 < num2
    {
        printf("\nResult : 0\n");
        return SUCCESS;
    }
    else if (cmp == 1) // num1 == num2
    {
        printf(flag == 2 || flag == 3 ? "\nResult : -1\n" : "\nResult : 1\n");
        return SUCCESS;
    }
    else if (cmp == SUCCESS) // num1 > num2
    {
        digit_to_list(head1, tail1, head2, tail2, num1, num2);
        division(head1, tail1, head2, tail2, headR, tailR, &result);
        printf(flag == 2 || flag == 3 ? "Result : -%ld\n" : "Result : %ld\n", result);
        return SUCCESS;
    }

    return FAILURE; // Safety return
}