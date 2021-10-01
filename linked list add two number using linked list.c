#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct NODE
{
	int data;
	struct NODE *next;
}list;
 list *head1,*head2;//initially these are assigned to 0
 static list *resulthead;
list *create(list *);
list *reverse(list *);
void display(list *);
void addlinkedlist(list *,list *);
void insertatbegin(int);

int main()
{
	int option;
	do
	{   printf("\nenter one digit at a time,it does not work for second time");
		printf("\n***Main Menu***");
		printf("\n1.ADD two numbers.");
		printf("\nEnter the option.");
		scanf("%d",&option);
		switch(option)
		{
			case 1:printf("\nEnter first list\n");
			       head1=create(head1);
			       printf("\n\nEnter second list\n");
			       head2=create(head2);
			       head1=reverse(head1);
			       printf("\nReversed first list successfully= ");
			         display( head1);
			       head2=reverse(head2);
			       printf("\nReversed second list successfully= ");
			         display( head2);
			         printf("\n");
			       addlinkedlist(head1,head2);
				   break;	       
		}
	}while(option>=1);
	getch();
	return 0;
}
void addlinkedlist(list *head1,list *head2)
{
  list *temp1,*temp2;
  temp1=head1,temp2=head2;
  int sum=0,carry,insertvalatbegin;
  while(temp1!=0 || temp2!=0)
  {
	sum=sum+(temp1!=0?temp1->data:0) + (temp2!=0?temp2->data:0);
	if(temp2!=0 || temp1!=0)
	{
		printf("%d",sum%10);
		//insertvalatbegin=sum%10;
		insertatbegin(sum%10);
	    sum=carry=sum/10;//carry will be added to sum
	}
	else if (sum>=10)
	{
		printf("%d",sum%10);
	 	//insertvalatbegin=sum%10; // if len is same and last contain carry then it work
	 	insertatbegin(sum%10);
		 carry=sum/10;
		 printf("%d",carry);
		 insertatbegin(carry);	
	}
	else
	{
		printf("%d",sum%10);
		//insertvalatbegin=sum%10;
		insertatbegin(sum%10);
	}
	
	if(temp1!=0)
	{
	  temp1=temp1->next;	
	}
	if(temp2!=0)        //right code
	{
	  temp2=temp2->next;	
	}
}
if((temp1==0 && temp2==0) & carry==1)
{
   printf("%d",carry);
    insertatbegin(carry);		
}
 printf("\nsum of two numbers using linked list = ");
  display(resulthead);
}


list *create(list *head)
{
  list *newnode,*temp;
  int n;
  printf("\nEnter -1 to stop entering numbers.");
  while(n!=-1)
  {
  	newnode=(list*)malloc(sizeof(list));
  	printf("\nenter the number= ");
  	scanf("%d",&newnode->data);
  	if(newnode->data== -1)
  	{
  		break;
	}
  	newnode->next=NULL;
  	if(head==0)
  	{
  	   head=temp=newnode;	
	}
	else
	{
	   temp->next=newnode;
		temp=newnode;	
	}
	
  }
   	printf("\n The number is= ");
   	display(head);
   	return head;
}
list *reverse(list *head)
{
  list *current,*nextnode,*prev;
  current=head;
  prev=0;
  while(current!=0)
  {
  	nextnode=current->next;
  	current->next=prev;
    head=prev=current;
    current=nextnode;	
  }
  return head;	
}

void display(list *head)
{
	if(head==0)
	{
		printf("\nno data");
	}
	else
	{
	list *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
    }
}
void insertatbegin(int value)
{ 
	list *newnode;
	newnode=(list*)malloc(sizeof(list));
	 if(resulthead==0)
	 {
	 	newnode->data=value;  //creating first node
	 	newnode->next=0;
	   resulthead=newnode;
	 }
	 else
	 {
	   newnode->data=value;	
	   newnode->next=resulthead;
	   resulthead=newnode;//updating head of result
	 }
}
