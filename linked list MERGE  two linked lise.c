#include<stdio.h>
#include<stdlib.h>
#include<conio.h>      //this code works noly for sorted list 
typedef struct NODE
{
	int data;
	struct NODE *next;
}list;
  list *head1,*head2;//initially these are assigned to 0
  static list *mergeresult,*mergeresulttail;
 list *createlist(list *);
  void mergelist(list *,list *);
 void displaylist(list *);
 void insertatend(int);
 int main()
 {
 	int option;
 	do
 	{
 		printf("\n***Main Menu***");
		printf("\n1.create list 1.");
		printf("\n2.create list 2.");
		printf("\n3.Merge two list.");
		printf("\n4.Display the merge list.");
		printf("\nEnter the option.");
		scanf("%d",&option);
		switch(option)
		{
			case 1:head1=createlist(head1);
				   break;
			case 2:head2=createlist(head2);
				   break;
		    case 3:mergelist( head1,head2);
				   break;
			case 4:displaylist(mergeresult);
				   break;	   	   
	   }
    }while(option<=4);
    getch();
    return 0;
 }
 list *createlist(list *head)
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
  return head;
}
 
 void displaylist(list *head)
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
		printf(" %d",temp->data);
		temp=temp->next;
	}
    }
}

void mergelist(list *head1,list *head2)
{
   list *mergeresult,*temp;
   while(head1!=0 && head2!=0)
   {
   	 if(head1->data <= head2->data)
   	 {
   	 	insertatend(head1->data);
   	 	head1=head1->next;
	 }
	 else if(head2->data <= head1->data)
	 {
	 	insertatend(head2->data);
   	 	head2=head2->next;
	 }
   }
   while(head1!=0)
   {
   	 	insertatend(head1->data);
   	 	head1=head1->next;
   }
   while(head2!=0)
   {
   	    insertatend(head2->data);
   	 	head2=head2->next;
   } 	 
}

void insertatend(int value)
{
  list *newnode,*temp;
  newnode=(list*)malloc(sizeof(list));
  newnode->next=0;
  if(mergeresult== 0)
  {
  	newnode->data=value;
  	mergeresult=mergeresulttail=newnode;	
  }
  else
  {
  	mergeresulttail->next=newnode;//linked
  	newnode->data=value;
  	mergeresulttail=newnode;
  } 	
}
