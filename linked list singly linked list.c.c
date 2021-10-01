#include<stdio.h>
#include<stdlib.h>//this is for using malloc function
#include<conio.h>
struct node
	{
	  int data;
	  struct node *next;	        //in this code we are not maintaining head or tail
	}*start=NULL;   
 struct node *createlinkedlist(struct node *);//putting * in in front of function means we are declaring a function returning a pointer or addresss of strut node
 struct node *displayallelement(struct node *);//it read as displayallelement is function returning pointer to struct node
 struct node *insertbeginning(struct node *);
 struct node *insertatend(struct node *);
 struct node *insertaftergivenposition(struct node *);
 struct node *insertbeforegivenposition(struct node *);
 struct node *deletenodebeginning(struct node *);
 struct node *deletenodeend(struct node *);
 struct node *deletegivenposition(struct node *);   
 struct node * reverse(struct node *);
 struct node * sortinassendingorder(struct node *);//we rae using struct node at first of function because this function going to return address and that address will be stored  struct node datatype
 struct node * removeduplicatesunsortedlist(struct node *);
 struct node *removeduplicatessortedlist(struct node *);
 
int main()
{
  int option;
  do
  {
  	printf("\n\n********MAIN MENU*********");
  	printf("\n1.create a list.");
  	printf("\n2.display the list.");
  	printf("\n3.Add a node at beginning.");
  	printf("\n4.Add a node at end.");
  	printf("\n5.Add a node after a given position.");
  	printf("\n6.Add a node before a given position.");
  	printf("\n7.Delete a node from the beginning.");
  	printf("\n8.Delete node from end.");
  	printf("\n9.Delete given position node.");
  	printf("\n10.Reverse the list");
  	printf("\n11.Sort in Assendingorder.");
  	printf("\n12.Remove duplicates of unsorted list.");
  	printf("\n13.Remove duplicates of sorted list.");
  	printf("\n14.EXIT\n");
  	printf("\nEnter your option:");
  	scanf("%d",&option);
  	switch(option)
  	{
  	  case 1:start=createlinkedlist(start);
		     printf("\nlinkedlist created\n");
		     break;   //it terminate switch function and enter in do while loop
	  case 2:start=displayallelement(start);
	         break;//it terminate switch function and enter in do while loop
	  case 3:start=insertbeginning(start);
	         break;
	  case 4:start=insertatend(start);
	         break;
	  case 5:start=insertaftergivenposition(start); 
	         break; 
	  case 6:start=insertbeforegivenposition(start); 
	         break;
	  case 7:start=deletenodebeginning(start);
	         break;
      case 8:start=deletenodeend(start); 
	         break;
	  case 9:start=deletegivenposition(start); 
	         break;
	  case 10:start=reverse(start); 
	         break;
	case 11:start=sortinassendingorder(start); 
         	break;
	case 12:start=removeduplicatesunsortedlist(start);  
	        break;
	case 13:start=removeduplicatessortedlist(start);  
	        break;		   
	case 14:exit(0);
	}
  }while(option<=14);
  getch();
  return 0;	  	
}
 struct node *createlinkedlist(struct node *head)//instead of head we can use start.we are using head because we sue head as variable in code
 {
        int n,i,count=0;
	    struct node *newnode,*temp;
	    head=0;//this is important to give here because when we dont give then when we run at first it will work but when we run econd time it produce error
	    printf("\nhow many data you want to enter:");
	    scanf("%d",&n);
	   for(i=0;i<n;i++)
     	{
        	newnode=(struct node*)malloc(sizeof(struct node));
         	printf("\nenter data:");
	        scanf("%d",&newnode->data);
	        newnode->next=0;
	        if(head==0) //this will execute only once because head=0; is declared so only first time condition will be true
	            {
	              // newnode->next=0; even here we can write and remove the previous one
	               head=temp=newnode;
             	}
        	else
          	{
	           	temp->next=newnode;
		        temp=newnode;
	        }
        }  
	    temp=head;
	    while(temp!=0)
	    {                 //displaying
		   printf("%d ",temp->data);
		   temp=temp->next;
		   count++;
	    }
	  printf("\nNumber of nodes=%d",count);
	  return head;	
 }
  struct node *displayallelement(struct node *head)
  {
     if(head==NULL)
     {
     	printf("\nNo data list is empty.");
	 }
	 else
	 {
  	 struct node *temp;
  	 temp=head;
  	 printf("\nelements are:");
	    while(temp!=0)
	    {
	    	printf(" %d",temp->data);
		    temp=temp->next;  
	    }
     }
	  return head;
  }
   struct node *insertbeginning(struct node *head)
   {
   	        struct node *newnode,*temp;
		    newnode=(struct node*)malloc(sizeof(struct node)); 
            printf("\nenter data to insert newnode at beginning of list:");
	        scanf("%d",&newnode->data);
	        newnode->next=head;                     //inserting newnode at beginning of list
	        head=newnode;
	        temp=head;
	        printf("\nData after inserting at beginning:");
	    while(temp!=0)
	    {
		   printf("%d ",temp->data);          //displaying the inserted node at beginning
		   temp=temp->next;
      	}
      	return head;
   }
   struct node *insertatend(struct node *head)
   {
   	        struct node *newnode,*temp;
   	        newnode=(struct node*)malloc(sizeof(struct node));
	    	printf("\nenter data to insert newnode at end of list:");
	        scanf("%d",&newnode->data);
   	        newnode->next=0;                    // inserting newnode at end of list
	        temp=head;
	        while(temp->next!=NULL)
	        {
	            temp=temp->next;            //traversing to reach last node	
			}
			temp->next=newnode;
			 temp=head;
	        printf("\n\nData after inserting at end of list: ");
	    while(temp!=0)
	    {
		   printf("%d ",temp->data);     //displaying the inserted node at end
		   temp=temp->next;
	    }
	    return head;
   }
    struct node *insertaftergivenposition(struct node *head)
    {
	        struct node *newnode,*temp;
	        int pos,j=1,count=0;
            newnode=(struct node*)malloc(sizeof(struct node));
        	printf("\nenter position to insert after the given position:");
        	scanf("%d",&pos);
        	temp=head;
        	while(temp!=0)
        	{
        	  temp=temp->next;  //counting number of nodes
			  count++;	
			}
			if(pos>count)
			{
				printf("\ninvalid position");
			}
			else
			{
			    temp=head;
				while(j<pos)
				{
				   	temp=temp->next;  //at position 0 than temp will contain address of first element because while loop condition fails so at pos 0 value will
				   	j++;              //be inserted after first element. whatever we enter position value will be inserted after the position
				}
				newnode->next=temp->next;
				temp->next=newnode;		
			}
			printf("\nEnter data to insert:");
			scanf("%d",&newnode->data);
			temp=head;
	        while(temp!=0)
	    {
		   printf("%d ",temp->data);     //displaying the inserted node after the  given position
		   temp=temp->next;
	    }
	    return head;
	}
	
	struct node *insertbeforegivenposition(struct node *head)
	{
	    struct node *newnode,*temp;
	    int count=0,j=1,pos;   
	    newnode=(struct node*)malloc(sizeof(struct node));
        	printf("\nenter position to insert before the  given position:");
        	scanf("%d",&pos);	
        	temp=head;
        	while(temp!=0)
        	{
        	  temp=temp->next;  //counting number of nodes
			  count++;	
			}
			if(pos>count)
			{
				printf("\ninvalid position");
			}
			else
			{
			    temp=head;
				while(j<pos-1)      //inserting  node before the  given position only here we have to make changes and we have to initialze value countagain=0,j=1;
				{
				   	temp=temp->next;  //at position 0 than temp will contain address of first element because while loop condition fails so at pos 0 value will be inserted after first element
				   	j++;               // we enter position value 0 than value will be inserted after the position
				}
				newnode->next=temp->next;
				temp->next=newnode;		
			}
			printf("\nEnter data to insert:");
			scanf("%d",&newnode->data);
			temp=head;
	        while(temp!=0)
	    {
		   printf("%d ",temp->data);      //displaying the inserted node before the  given position
		   temp=temp->next;
    	}
		return head;	
	}
	
	 struct node  *deletenodebeginning(struct node *head)
	 {
	 	if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		 }
		else
	    {
	 	displayallelement(head);
	    struct node *temp;
	    temp=head;
	     head=head->next; //when there is one node in list and user delete it then this statement head will contain 0 because when there is one node next data will contain 0 so 0 will be stored in head
	     free(temp);      //freeing first node memory
	     printf("\nfirst node deleted successfully.\n");
	     printf("\nData after deleting first node from list.");
	     displayallelement(head);
	  	}
	     return head;
	 }
	 
	  struct node *deletenodeend(struct node *head)
	  {
	  	if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		 else
		 {
		    struct node *prenode,*temp;
		    displayallelement(head);
			temp=head; 
			while(temp->next!=0)
			{
			  prenode=temp;
			  temp=temp->next;	
			}
			if(temp==head)
			{
				head=0;
				free(temp);
		    }
			else
			{
			   prenode->next=0;
			   free(temp);	
			} 
			printf("\nLast node deleted successfully.");
			printf("\nData after deleting last node.");	
			displayallelement(head);
		 }
		 return head;
	  }
	  
	  struct node *deletegivenposition(struct node *head)
	  {
	  	if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		else
		{
			struct node *nextnode,*temp;
			int i=1,pos;
			printf("\nEnter position to delete node:");
			scanf("%d",&pos);
		    displayallelement(head);
		    temp=head;
		    while(i<pos-1)
		    {
		      temp=temp->next;
			  i++;	
			}
			if(pos==1)
			{
				if(temp->next==0)
				{
					head=0;
					free(temp);
				}
				else //temp->next!=0 if this is true then else will execute 
				{
				   temp=head->next;  //here we have to delete head node and again initialize to head as start of node
				   free(head);
				   head=temp;
				}
				printf("\nSelected position deleted successfully.");
			    printf("\nData after deleting Selected position.");	
			    displayallelement(head); 
			}
			else
			{
			nextnode=temp->next;
			temp->next=nextnode->next;
			free(nextnode);
			printf("\nSelected position deleted successfully.");
			printf("\nData after deleting Selected position.");	
			displayallelement(head); 
	    	}
	    	return head;
		}
	  }
	  
	   struct node * reverse(struct node *head)
	   {
	   	 struct node *prevnode,*currentnode,*nextnode;
	   	 prevnode=0; //first we have to set prevnode=0 because first node is last node and last node does not not contin any address
	   	 currentnode=nextnode=head;
	   	 while(nextnode!=0)
	   	 {                             
	   	    nextnode=nextnode->next;    
		    currentnode->next=prevnode;
			prevnode=currentnode; //so that next node would contain the address of previous node
			currentnode=nextnode;  	 	
		 }
		 head=prevnode;//here previous node contain the last node which is starting node after reversing so maintaining head
		 printf("\nIn reverse order: ");
		 struct node *temp;
  	     temp=head;
	    while(temp!=0)
	    {
	    	printf(" %d",temp->data);
		    temp=temp->next;
		     
	    }
		 return head;
	   }
	   
	struct node * sortinassendingorder(struct node *head)
 {
	   	 struct node *temp,*nextnode ;
	   	 int  swap;
  	     temp=head;
	    while(temp->next!=0)
	    {
	    	nextnode=temp->next;
	    	while(nextnode!=0)
	    	{
	    		if(temp->data >=nextnode->data)// > = inbetween space not allowed
	    		{
	    			swap=temp->data;
	    			temp->data=nextnode->data;
	    			nextnode->data=swap;
				}
				   nextnode=nextnode->next;
			}
			temp=temp->next;
		}
		  
	  head=displayallelement(head);
	  return head;
}

 struct node * removeduplicatesunsortedlist(struct node *head)//unsorted list
 {
 	struct node *temp,*nextnode,*traversedata,*deletenode;
 	int i,pos,j=1,k=0,noduplicate=0;
 	temp=head;
 	if(head->next==0)
 	{
 		printf("\nonly one node is present");
 		printf("\n%d",head->data);
 		return head;//here if condition is true then program will run till here only
	 }
 	while(temp!=0)
 	{
 	  i=++k;//to get right position
	  nextnode=temp->next;
	   while(nextnode!=0)
	    {
	   	  pos=++i;//for position
	   	    if(temp->data==nextnode->data)
	   	      {
	   	       noduplicate=1;//when there is duplicate node then statement will indicate that there is duplicate node	
	   	      	j=1;//to reach to right position j should start with 1
	   	      	traversedata=head;//so that while statement will execute from start to reach to the position
	   	      	  while(j<pos-1)
	   	      	   {
	   	      	  	 traversedata=traversedata->next;
	   	      	  	 j++;
				   }
				   nextnode=traversedata;//when a node is deleted so this will hold previous node so this statement  nextnode=nextnode->next; will execute correctly
				   deletenode=traversedata->next;
				   traversedata->next=deletenode->next;//node is linked
				   free(deletenode);
				   --i;//when a node is deleted then element present in list is decreased
			   }
			  nextnode=nextnode->next;
		}
		temp=temp->next; 	
	}
	if(noduplicate==0)
	{
		printf("No duplicates present in list.");
	}
	else
	{
	printf("\nAfter removing Duplicates:");
	}
	head=displayallelement(head);
	return head;
 }
 
  struct node *removeduplicatessortedlist(struct node *head)
  {
  		struct node *temp,*deletenode;
  		temp=head;
  		while(temp->next!=0)
  		{
  		  if(temp->data==temp->next->data)
			{
			   deletenode=temp->next;
			   temp->next=temp->next->next;
			   free(deletenode) ;	
			}
			else//else is used because when temp=0 then in while loop temp->next is illegal to access so else is used 
			temp=temp->next;	
		}
		printf("\nAfter removing duplicates from sorted list:");
			head=displayallelement(head);
			return head;
		}
		
