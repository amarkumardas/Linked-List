#include<stdio.h>   
#include<stdlib.h>//this is for using malloc function
#include<conio.h>
struct node                         //to insert or delete we have to maintain both head and tali to make fast algorithm
	{                
	  struct node *prev;
	  struct node *data;
	  struct node *next;	
	};
	  struct node *tail=0;//this is useful when we directly try to display or insert the node without inserting anything that time head will be 0 and will be printed no data in list
	 struct node *head=0;
 void createlinkedlist( );
 void displayallelement( );
 void insertbeginning( );
 void insertatend();//error-> insertatend(); since this function is not returning anything then we have to use void which means nothing will return  otherwise error 
 void insertatgivenposition( );
// struct node *insertaftergivenposition(struct node *);
// struct node *insertbeforegivenposition(struct node *);
 void deletefrombegin( );
 void deletefromend( ); 
 void deletegivenposition( ); 
 void reverse();
 void sortinassendingorder();
 void removeduplicatesunsortedlist(); 
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
  	printf("\n6.Delete a node from the beginning.");
  	printf("\n7.Delete node from end.");
  	printf("\n8.Delete given position node.");
  	printf("\n9.Reverse the list.");
  	printf("\n10.Sort in assending order.");
  	printf("\n11.Remove duplicates of unsorted list.");
  	printf("\n12.EXIT\n");
  	printf("\nEnter your option:");
  	scanf("%d",&option);
  	switch(option)
  	{
  	case 1: createlinkedlist( ); 
		     break;
	case 2:displayallelement( );//return not needed
	        //printf("\nlast data %d",tail->next->data); //when there is no data and we enter 2 then tail has no initial value and we are trying to access tail->next->data while is error so in this situation this statement will produce error
	         break;//it terminate switch function and enter in do while loop
	case 3: insertbeginning( );
	         break;
    case 4: insertatend();  //here we cant use  void insertatend(void); insertatend(void);
	         break;
   case  5: insertatgivenposition( );
	         break;
    case 6:deletefrombegin( );
	        break;
    case 7: deletefromend( );
	        break;
 	case 8: deletegivenposition( );  
	        break;
    case 9:reverse();
	        break;
	case 10:sortinassendingorder();
	        break;
	case 11:removeduplicatesunsortedlist();  
	        break;    		        
	case 12:exit(0);
	}
  }while(option<=12);
  getch();
  return 0;
}

 void createlinkedlist( )
   {
   	  int n,i,count=0;
	    struct node *newnode,*temp;
	    printf("\nhow many data you want to enter:");
	    scanf("%d",&n);
	if(n==0)
   { 
	 printf("\nyou have selected 0 so No data is inserted.");
   }
    else
    {
	   for(i=0;i<n;i++)
     	{
        	newnode=(struct node*)malloc(sizeof(struct node));
         	printf("\nenter data:");
	        scanf("%d",&newnode->data);
	        if(head==0) //this will execute only once because head=0; is declared so only first time condition will be true
	            {
	               head=tail=newnode;//here tail and head is maintained 
	               newnode->prev=tail;//newnode->prev=head; //because head=tail=newnode are same when there is no data
	               newnode->next=head;
             	}
        	else
          	{
          		tail->next=newnode;
          	  	newnode->prev=tail;
				newnode->next=head;
				head->prev=newnode;
				tail=newnode;//maintaining tail  
	        }
        }
		temp=head;
	    while(temp!=tail)//while(temp->next!=tail->next)
	    {
		   printf("%d ",temp->data);
		   temp=temp->next;
		   count++;
	    }
	     printf("%d ",temp->data);
	  printf("\nNumber of nodes=%d",count+1);
   } 
	  	  
 }
 
   void displayallelement()
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
	    while(temp->next!=tail->next)//or while(temp!=tail)
	    {
	    	printf(" %d",temp->data);
		    temp=temp->next;
	    }
	     printf(" %d ",temp->data);   
    }
  }	
  
  void insertbeginning()
   {
   	        if(head==0)//NULL
     {
     	printf("\nNo data list is empty.");
     	printf("\nenter 1 to create list");
	 }
	 else
	 {
   	        struct node *newnode,*temp;
		    newnode=(struct node*)malloc(sizeof(struct node)); 
            printf("\nenter data to insert newnode at beginning of list:");
	        scanf("%d",&newnode->data);
	        newnode->next=head;
	        head->prev=newnode;
	        newnode->prev=tail;//linking circular
			head=newnode;
	        tail->next=head;//updating tail->next that is head
			temp=head;
	    while(temp!=tail)
	    {
		   printf("%d ",temp->data);          //displaying the inserted node at beginning
		   temp=temp->next;
      	}
      	 printf("%d ",temp->data); 
     }	         
   }
   
 void insertatend( )
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
	        newnode->prev=tail;
	        tail->next=newnode;
	        newnode->next=head;
	        head->prev=newnode;
	        tail=newnode;//maintaining tail
			 temp=head;
	        printf("\n\nData after inserting at end of list: ");
	    while(temp!=tail)
	    {
		   printf("%d ",temp->data);     //displaying the inserted node at beginning
		   temp=temp->next;
	    }
	    printf("%d ",temp->data);  
	    } 
	}
  
  void insertatgivenposition( )
	{//1
			if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		else
		{//2
			struct node *newnode,*temp ;
	        int count=1,j=1,pos,i=1;   
        	printf("\nenter position to insert: ");
        	scanf("%d",&pos);
        	temp=head;
        	while(temp!=tail)
        	{
        	  temp=temp->next;  //counting number of nodes
			  count++;	
			}
			if(pos>count)
			{
				printf("\ninvalid position");
			}
			else
			{//3
				if(pos==1 || pos==0)     // whenever user enter pos 1 or 0 then only it will execute
				{
				  insertbeginning();	
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
				 newnode->prev=temp;
				 newnode->next=temp->next;
				 temp->next->prev=newnode;//using multiple pointer
				 temp->next=newnode;
				 printf("\nAfter inserting newnode at given position.");
		     	 displayallelement( );
		     	}	  
			}//3
		}//2
	}//1
	
	  void deletefrombegin( )
    {
	 	if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		 }
		else
	    {
	 	displayallelement( );
	    struct node *temp;
	     temp=head;
		 if(head->next==head) //when there is only one node than only it will execute
		 {
	        free(temp);
	        head=tail=0;  
	     }
	     else 
	     {
	        head=head->next;
			head->prev=tail;
			tail->next=head;
			free(temp);	
		 } 
		 printf("\nfirst node deleted successfully.\n");
	     printf("\nData after deleting first node from list.");
	     displayallelement( );
	  	}
	 }
	 
	 void deletefromend( )
	  {
	  		if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		 else
		 {
		    struct node *temp;
		    displayallelement( );
		   if(head->next==head)
		   {
			 free(head);
			 head=tail=0;
		   }
		    else
		    {
		      temp=tail;
		      tail=tail->prev;//maintaining tail
			  tail->next=head;
			  head->prev=tail;//updating to first node
			  free(temp);	
			}
			printf("\nLast node deleted successfully.");
			printf("\nData after deleting last node.");	
			displayallelement();
		 }
	  }
	  
	void deletegivenposition( )
	{//1
	  	if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		else
		{//2
			struct node *nextnode,*temp;
			int i=1,pos,count=1;
			printf("\nEnter position to delete node:");
			scanf("%d",&pos);
		    temp=head;
		    	while(temp!=tail)// or while(temp->next!=tail->next)
        	{
        	  temp=temp->next;  //counting number of nodes
			  count++;	
			}
			if(pos>count)
			{
				printf("\ninvalid position");
			}
			else
			{//3
			  if(pos!=1 && pos!=count && pos!=0) //pos!=0 whenever user entered 0 then if condition should become false so pos!0 is given in if condition
			    {
				  temp=head;
				  displayallelement( );
				  while(i<pos-1)
				   {
				     temp=temp->next;
				     i++;	
				   }
				  nextnode=temp->next;
				  temp->next=nextnode->next;
			      nextnode->next->prev=temp;
				  free(nextnode);
				  /*while(i<pos)
				  {
				  	temp=temp->next;    //both works but is better then first one because here we dont need extra pointer
				  	i++;
				  }
				  temp->prev->next=temp->next;   //using multiple pointer we can also go reverse
				  temp->next->prev=temp->prev; //using multiple pointer
				  free(temp);
				  */
			   	  printf("\nSelected position deleted successfully.");
			      printf("\nData after deleting Selected position.");	
			      displayallelement( ); 	
		    	}
			else if(pos==1 || pos==0 )
			{
			   deletefrombegin( );
			}
			else//when pos==count
			{
			   	deletefromend( ); 	
			}	
		}//3
	}//2
   }//1
   
    void reverse()
    {
    	if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		else
		{
       struct node *currentnode,*nextnode;
	   currentnode=head;
	    while(currentnode->next!=head)
		{
		  nextnode=currentnode->next;
		  currentnode->next=currentnode->prev;
		  currentnode->prev=nextnode;
		  currentnode=nextnode;	
		}
		 nextnode=currentnode->next;
		 currentnode->next=currentnode->prev;
		 currentnode->prev=nextnode;
		 	tail=head;
		 	head=currentnode;
		printf("\nAfter reversing:");
		displayallelement( );
     	}
	}
	
void sortinassendingorder()
	{
			if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		else
		{
	    struct node *nextnode,*temp;
	       struct node *swap;//or int swap; this gives warring but works in other program it dooes not give warring but here it gives warring  
		   temp=head;
		   while(temp->next!=head)	
		   {
		   	  nextnode=temp->next;
		   	   while(nextnode!=head)
		   	   {
		   	   	 if(temp->data >=  nextnode->data)
		   	   	 {
		   	   	   swap=temp->data;
				   temp->data=nextnode->data;
				   nextnode->data=swap;		 	
				 }
				 nextnode=nextnode->next;	  
			  }
			  temp=temp->next;
		   }
		   printf("\nAfter sorting:");
		   displayallelement( );
    	}
	}
	
	void removeduplicatesunsortedlist()
	{
		struct node *temp,*nextnode,*traversedata,*deletenode;
 	    int i,pos,j=1,k=0,noduplicate=0;
 	    temp=head;
 	    if(head->next==head)
  	      {
 		    printf("\nonly one node is present");
 	     	printf("\n%d",head->data);
	       }
	       else
	       {//1
 	while(temp->next!=head)
 	{
 	  i=++k;//to get right position
	  nextnode=temp->next;
	   while(nextnode!=head)
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
				   deletenode->next->prev= traversedata;
				   free(deletenode);
				   --i;//when a node is deleted then element present in list is decreased
			   }
			  nextnode=nextnode->next;
		}
	  temp=temp->next; 	
	}
	tail=temp;//if last node is duplicate then it will be deleted so we have to maintain tail temp contain tail address
	if(noduplicate==0)
	{
		printf("No duplicates present in list.");
	}
	else
	{ 
	 printf("\nAfter removing Duplicates:");
	}
	displayallelement( );
	}//1
}
	
