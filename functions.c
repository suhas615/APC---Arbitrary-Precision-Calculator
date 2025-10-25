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

int is_digits(char *num1,char *num2,int a,int b)
{
	int i=a;

	while(num1[i]!='\0')
	{
		if(isdigit(num1[i])==0)
		{
		   printf("INFO: Invalid arguments\n");
		   return FAILURE;
		}
		i++;
	}
	i=b;
	while(num2[i]!='\0')
	{
		if(isdigit(num2[i])==0)
		{
		   printf("INFO: Invalid arguments\n");
		   return FAILURE;
		}
		i++;
	}
	return SUCCESS;
}
int read_and_validation(int argc,char *argv[])
{
    if(argc!=4)
	{
		printf("INFO:Insufficient Arguments\n");
        return FAILURE;
	}

    if(argv[3][0] == '-' && argv[1][0]=='-')
    {
        
        if(is_digits(argv[1],argv[3],1,1)==FAILURE)
        {
            return FAILURE;
        }
    }
    else if(argv[1][0]=='-')
    {
        if(is_digits(argv[1],argv[3],1,0)==FAILURE)
        {
            // printf("\n11\n");
            return FAILURE;
        }
    }
    else if(argv[3][0]=='-')
    {
        if(is_digits(argv[1],argv[3],0,1)==FAILURE)
        {
            // printf("\n22\n");
            return FAILURE;
        }
    }
    else if(argv[3][0]!='-'&&argv[1][0]!='-')
    {
        if(is_digits(argv[1],argv[3],0,0)==FAILURE)
        {
            // printf("\n33\n");
            return FAILURE;
        }   
    }
    

    if(strlen(argv[2])!=1)
    {
        return FAILURE;
    }
	if ((argv[2][0] == '+' || argv[2][0] == 'x' || argv[2][0] == '/' || argv[2][0] == '-' || argv[2][0] == '%'))
    {
        return SUCCESS;
    }
	else
    {
        printf("\nINFO: Please pass valid operator[+,-,x,/]\n");
        return FAILURE;
    }
    return SUCCESS;
}
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *num1,char *num2)
{
    int i = 0;
    while(num1[i]!='\0')
    {
            
        int data = num1[i] -'0';
        insert_last(head1,tail1,data);
        i++;
    }
    i = 0;
    while(num2[i]!='\0')
    {
        int data = num2[i] - '0';
        insert_last(head2,tail2,data);
        i++;
    }
    
}
int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new =malloc(sizeof(Dlist));
    
	if (new==NULL)
	{
        return FAILURE;
	}
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    else
    {
        new->prev=*tail;
        (*tail)->next=new;
        *tail=new;
        return SUCCESS;
    }
}

int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new =malloc(sizeof(Dlist));
    
	if (new==NULL)
	{
        printf("INFO: Insert last fails\n");
		return FAILURE;
	}
	
    
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        
    }
    else
    {
        new->next=*head;
        (*head)->prev=new;
        *head=new;
        
    }
    return SUCCESS;
}

int delete_list(Dlist **head,Dlist **tail)
{
	if(*head==NULL)
    {
        return FAILURE;
    }
    if(*head==*tail)
    {
        free(*head);
        *head=*tail=NULL;
        return SUCCESS;
    }
    
    
    while(*tail != NULL)
    {
        if(*head==*tail)
        {
            free(*head);
            *head=*tail=NULL;
            return SUCCESS;
        }
        Dlist *temp;
        temp=*tail;
        *tail=temp->prev;
        (*tail)->next=NULL;
    }
    return SUCCESS;
}
void print_list(Dlist *headR,int data)
{
    /* Cheking the list is empty or not */
	if (headR == NULL)
	{
        printf("INFO : List is empty\n");
	}
	else
	{
        Dlist *temp=headR;
        printf("Result : ");
		if(data==1)
		{
            printf("-");
		}
	    while (temp!=NULL)		
	    {
            printf("%d", temp -> data);
		    temp = temp -> next;
	    }
    	printf("\n");
    }
}

int identify_greater(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *num1,char *num2)
{
    if(strlen(num1)>strlen(num2))
    {
        digit_to_list(head1,tail1,head2,tail2,num1,num2);
        return SUCCESS;
    }
    else if (strlen(num1)<strlen(num2))
    {
        digit_to_list(head1,tail1,head2,tail2,num2,num1);
        return FAILURE;
    }

    if(strcmp(num1,num2)>0)
    {
        digit_to_list(head1,tail1,head2,tail2,num1,num2);
        return SUCCESS;
    }
    else if(strcmp(num1,num2)==0)
    {
        digit_to_list(head1,tail1,head2,tail2,num1,num2);
        return SUCCESS;
    }
    else if(strcmp(num1,num2)<0)
    {
        digit_to_list(head1,tail1,head2,tail2,num2,num1);
        return FAILURE;
    }
}

int cancel_zero(Dlist **head,Dlist **tail)
{
   if(*head==NULL)
   {
       printf("INFO: head1 is empty\n");
       return FAILURE;
   }
   if(*head == *tail)
   {
        return SUCCESS;
   }
   Dlist *temp=*head;
   while(temp != NULL)
   {
       if(*head == *tail)
       {
           return SUCCESS;
       }
       if(temp->data == 0)
       {
           *head = temp->next;
           (*head)->prev = NULL;
           free(temp);
           temp = *head;
       }
       else if(temp->data != 0)
       {
           return SUCCESS;
       }
       if(*head == *tail)
       {
            return SUCCESS;
       }
       
   }
}
int is_greater(char *num1,char *num2)
{
    if(strlen(num1)>strlen(num2))
    {
        return SUCCESS;
    }
    else if(strlen(num1)<strlen(num2))
    {
        return FAILURE;
    }
    if(strcmp(num1,num2)>0)
    {
        return SUCCESS;
    }
    else if(strcmp(num1,num2)<0)
    {
        return FAILURE;
    }
    
    if (strcmp(num1,num2)==0)
    {
        return 1;
    }
}
int is_larger(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    
    Dlist *t1 = *head1;
    Dlist *t2 = *head2;
    long long unsigned int len_1=0,len_2=0;

    while(t1 != NULL)
    {
        len_1++;
        t1 = t1->next;
    }

    while(t2 != NULL)
    {
        len_2++;
        t2 = t2->next;
    }
    if(len_1>len_2)
    {
        return SUCCESS;
    }
    else if(len_1<len_2)
    {
        printf("11\n");
        return FAILURE;
    }

    t1 = *head1;
    t2 = *head2;

    char *num1 = malloc(sizeof(char)*(len_1+1));
    char *num2 = malloc(sizeof(char)*(len_2+1));
    int i = 0;
    while(t1!=NULL)
    {
        num1[i]=(t1->data)+'0';
        i++;
        t1=t1->next;
    }
    num1[i]='\0';

    i=0;
    while (t2!=NULL)
    {
        num2[i]=(t2->data)+'0';
        i++;
        t2=t2->next;
    }
    num2[i]='\0';


    if(strcmp(num1,num2)>0)
    {
        return SUCCESS;
    }
    else if (strcmp(num1,num2)<0)
    {
        return FAILURE;
    }
    else if(strcmp(num1,num2)==0)
    {
        return SUCCESS;
    }
}
void flag_condition(char *num1,char *num2,int *flag)
{
    if(num1[0]!= '-'&& num2[0]!= '-')
    {
        *flag = 1;
    }
    else if(num1[0]!='-' && num2[0]== '-')
    {
        *flag = 2;
    }
    else if(num1[0]=='-' && num2[0]!= '-')
    {
        *flag = 3;
    }
    else if(num1[0]== '-' && num2[0]== '-')
    {
        *flag = 4;
    }
}
