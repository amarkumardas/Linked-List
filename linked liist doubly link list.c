#include<stdio.h>
#include<stdlib.h>//this is for using malloc function
#include<conio.h>
struct node
	{
	  int data;                                              //in this code we are not maintaining tail
	  struct node *first;                 //Doubllinked list
	  struct node *next;	
	}*head=NULL;
// struct node *storetail(struct node *);   
 struct node *createlinkedlist(struct node *);
 struct node *displayallelement(struct node *);
 struct node *insertbeginning(struct node *);
 struct node *insertatend(struct node *);
 struct node *insertatgivenposition(struct node *);
 struct node *insertaftergivenposition(struct node *);
 struct node *insertbeforegivenposition(struct node *);
 struct node *deletefrombegin(struct node *);
 struct node *deletefromend(struct node *); 
 struct node *deletegivenposition(struct node *); 
 struct node *reverse(struct node *); 
 struct node * sortinassendingorder(struct node *); 
 struct node * removeduplicatesunsortedlist(struct node *);
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
  	printf("\n5.Add a node at given position.");
  	printf("\n6.Add a node after a given position.");
  	printf("\n7.Add a node before a given position.");
  	printf("\n8.Delete a node from the beginning.");
  	printf("\n9.Delete node from end.");
  	printf("\n10.Delete given position node.");
  	printf("\n11.Reverse.");
  	printf("\n12.Sort in assending order.");
  	printf("\n13.Remove duplicates of unsorted list.");
  	printf("\n14.EXIT\n");
  	printf("\nEnter your option:");
  	scanf("%d",&option);
  	switch(option)
  	{
  	  case 1:head=createlinkedlist(head);
		     printf("\nlinkedlist created\n");
		     break;
	  case 2:head=displayallelement(head);
	         break;//it terminate switch function and enter in do while loop
	  case 3:head=insertbeginning(head);
	         break;
	  case 4:head=insertatend(head);
	         break;
      case  5:head=insertatgivenposition(head);
	         break;
	 case  6:head=insertaftergivenposition(head);
	         break;
	 case 7:head=insertbeforegivenposition(head);
	         break;
	 case 8:head=deletefrombegin(head);
	        break;
	 case 9:head=deletefromend(head);
	        break;
	 case 10:head=deletegivenposition(head);  
	        break; 
	 case 11:head=reverse(head);
	        break;
	case  12:head=sortinassendingorder(head);
	        break;
	case 13:head=removeduplicatesunsortedlist(head);  
	        break;   		        
	 case 14:exit(0);
	}
  }while(option!=14);
  getch();
  return 0;
}
  
   struct node *createlinkedlist(struct node *head)
   {
   	  int n,i,count=0;
	    struct node *newnode,*temp;
	    head=0;
	    printf("\nhow many data you want to enter:");
	    scanf("%d",&n);
	   for(i=0;i<n;i++)
     	{
        	newnode=(struct node*)malloc(sizeof(struct node));
         	printf("\nenter data:");
	        scanf("%d",&newnode->data);
	        newnode->first=0;
	        newnode->next=0;
	        if(head==0) //this will execute only once because head=0; is declared so only first time condition will be true
	            {
	               head=temp=newnode;
             	}
        	else
          	{
          		 temp->next=newnode;
	           	 newnode->first=temp;
	           	 temp=newnode;
	        }
        }
		temp=head;
	    while(temp!=0)
	    {
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
	        newnode->first=0;                     //inserting newnode at beginning of list
	       // newnode->next=0;  //no need to write
	       newnode->next=head;
	       head->first=newnode;
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
   	        if(head==NULL)
	     	{
	 		printf("\nNo data list is empty.");
	      	}
	      	else
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
			newnode->first=temp;
			 temp=head;
	        printf("\n\nData after inserting at end of list: ");
	    while(temp!=0)
	    {
		   printf("%d ",temp->data);     //displaying the inserted node at beginning
		   temp=temp->next;
	    }
	    }//else break
	    return head;
	}
	
	struct node *insertatgivenposition(struct node *head)
	{
			if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		else
		{
			struct node *newnode,*temp,*storeadd;
	        int count=0,j=1,pos,i=1;   
        	printf("\nenter position to insert: ");
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
				if(pos==1 || pos==0)     // whenever user enter pos 1 or 0 then first node will be modified
				{
				  head=insertbeginning(head);	
				}
				else
				{
			     newnode=(struct node*)malloc(sizeof(struct node));
			     printf("\nEnter data to insert at given position: ");
			     scanf("%d",&newnode->data);
			     	temp=head;//for traversing
			     while(i<pos-1)
				 {
				 	temp=temp->next;
				 	i++;
				 }
				newnode->first=temp; 
				 storeadd=temp->next;//temp->next contain address of next node
				 temp->next= newnode;
				 newnode->next= storeadd;
				 storeadd->first=newnode;
				/* newnode->first=temp;
				 newnode->next=temp->next;
				 temp->next=newnode;
				 newnode->next->first=newnode;//using multiple pointer*/
		     	}//else
			}//else
		}//else
		return head;
	}
	
	 struct node *insertaftergivenposition(struct node *head)
	 {
	 		if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		else
		{
	   struct node *newnode,*temp;
	        int pos,j=1,count=0;
	        newnode=(struct node*)malloc(sizeof(struct node)); ///this should be here beccause we are going to use newnode 
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
				   	temp=temp->next;  //at position 0 than temp will contain address of first element because while loop condition will  fails so at pos 0 value will be inserted after first element
				   	j++;               //whatever we enter position value will be inserted after the position
				}
				if(temp->next!=0)
				{
				 newnode->first=temp;
				 newnode->next=temp->next;
				 temp->next=newnode;
				 newnode->next->first=newnode;//using multiple pointer
	            } 
			  else //temp->next==0  when the user want to insert after the last node then this will execute
			  {
			  	 temp->next=newnode;
			  	 newnode->first=temp;   
			  	 newnode->next=0; 
			  }
			
			  printf("\nEnter data to insert:");
			    scanf("%d",&newnode->data);
		    	temp=head;
	            while(temp!=0)
	            {
		           printf("%d ",temp->data);          //displaying the inserted node after the  given position
		           temp=temp->next;
	            }  
        	}
	   }
	     return head;
	}
	
	 struct node *insertbeforegivenposition(struct node *head)
	 {
	    	if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		else
		{
	   struct node *newnode,*temp;
	        int pos,j=1,count=0;
	        newnode=(struct node*)malloc(sizeof(struct node)); ///this should be here beccause we are going to use newnode 
        	printf("\nenter position to insert before the given position:");
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
			    if(pos==0 || pos==1)
			    {
			    	head=insertbeginning(head);
				}
				else
				{
				while(j<pos-1)
				{
				   	temp=temp->next;  //at position 0 than temp will contain address of first element because while loop condition will  fails so at pos 0 value will be inserted after first element
				   	j++;               //whatever we enter position value will be inserted after the position
				}
			 
				 newnode->first=temp;
				 newnode->next=temp->next;
				 temp->next=newnode;
				 newnode->next->first=newnode;//using multiple pointer
			  printf("\nEnter data to insert:");
			    scanf("%d",&newnode->data);
		    	temp=head;
	            while(temp!=0)
	            {
		           printf("%d ",temp->data);          //displaying the inserted node after the  given position
		           temp=temp->next;
	            } 
			  }
        	}
	   }
	     return head; 	
	
	 }
   
    struct node *deletefrombegin(struct node *head)
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
		 if(head->next!=0) 
		 {
	     head=head->next;
	     head->first=0;
	     free(temp);
	     }
	     else//(head->next==0) 
	     {
	        head=0;
			free(temp);	 	
		 } 
		 printf("\nfirst node deleted successfully.\n");
	     printf("\nData after deleting first node from list.");
	     displayallelement(head);
	  	}
	     return head;
	 }
	  struct node *deletefromend(struct node *head)
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
			int i=1,pos,count=0;
			printf("\nEnter position to delete node:");
			scanf("%d",&pos);
		    displayallelement(head);
		    temp=head;
		    	while(temp!=0)
        	{
        	  temp=temp->next;  //counting number of nodes
			  count++;	
			}
			if(pos>count)
			{
				printf("\nyou have entered invalid position");	
			}
			else
			{
				 temp=head;
		    while(i<pos-1)
		    {                           //traversing to that position
		      temp=temp->next;
			  i++;	
			}
			if(pos==1 || pos==0)
			{
				 temp=head;//not needed here because when pos==0 then while loop will not execute and temp will not change
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
			}
			else
			{
			nextnode=temp->next;
			temp->next=nextnode->next;
			free(nextnode);	  
	    	}
	    		printf("\nSelected position deleted successfully.");
			    printf("\nData after deleting Selected position.");	
			    displayallelement(head); 
		}	
    	}
	return head;
	}
	
	 struct node *reverse(struct node *head)
	 {
	 	 if(head==NULL)
     {
     	printf("\nNo data list is empty.");
	 }
	 else
	 {
	 	struct node *currentnode,*nextnode,*holdlastnode;
	 	currentnode=head;
	 	while(currentnode!=0)
	 	{
	 		holdlastnode=currentnode;
	 		nextnode=currentnode->next;
	 		currentnode->next=currentnode->first;
	 		currentnode->first=nextnode;
	 		currentnode=nextnode;
		 }
		 head=holdlastnode;
		 head=displayallelement(head);
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
 struct node * removeduplicatesunsortedlist(struct node *head)
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
