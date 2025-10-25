/*
Name : S Suhas
Batch - 24030A
Project Name->Arbitary precision Calculator
*/
#ifndef APC_H
#define APC_H


#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*store the operands into the list */
int read_and_validation(int argc,char *argv[]);

void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *num1,char *num2);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,Dlist **headR1,Dlist **tailR1,Dlist **headR2,Dlist **tailR2);

/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,long int *data);

/*Insert nodes*/
int insert_last(Dlist **head, Dlist **tail, int data);

int insert_first(Dlist **head, Dlist **tail, int data);

int delete_list(Dlist **head, Dlist **tail);

void print_list(Dlist *headR,int data);

int identify_greater(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *num1,char *num2);

int cancel_zero(Dlist **head,Dlist **tail);

int is_greater(char *num1,char *num2);

int is_larger(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

void flag_condition(char *num1,char *num2,int *flag);

int spcl_cases_of_addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *num1,char *num2);

int spcl_case_of_subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *num1,char *num2);

int spcl_case_of_multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,Dlist **headR1,Dlist **tailR1,Dlist **headR2,Dlist **tailR2,char *num1,char *num2);

int spcl_case_of_division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *num1,char *num2);

#endif