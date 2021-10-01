#include<stdio.h>
#include<stdlib.h>//this is for using malloc function
#include<conio.h>
struct node                         //to insert or delete we have to maintain both head and tali to make fast algorithm
	{
	  struct node *data;                 
	  struct node *next;	
	};
	static struct node *tail=0;//this is useful when we directly try to display or insert the node without inserting anything that time head will be 0 and will be printed no data in list
	static struct node *head=0;
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
 void sortinassendingorder(void ); //void not necessary
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
  	printf("\n6.Add a node after a given position.");
  	printf("\n7.Add a node before a given position.");
  	printf("\n8.Delete a node from the beginning.");
  	printf("\n9.Delete node from end.");
  	printf("\n10.Delete given position node.");
  	printf("\n11Reverse the list.");
  	printf("\n12.sort in assending order.");
  	printf("\n13.Remove duplicates of unsorted list.");
  	printf("\n14.EXIT\n");
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
	 case 4: insertatend();  //we cant use -> void insertatend(void); insertatend(void);
	         break;
    case  5: insertatgivenposition( );
	         break;
	 /* case  6:head=insertaftergivenposition(head);
	         break;
	 case 7:head=insertbeforegivenposition(head);
	         break;*/
	  case 8:  deletefrombegin( );
	        break;
      case 9: deletefromend();//error deletefromend(void );
	        break;
	case 10: deletegivenposition( );  
	        break;
	case 11:reverse ();
	        break;
	case 12:sortinassendingorder( );
	        break;
	case 13:removeduplicatesunsortedlist();  
	        break;  		        
	 case 14:exit(0);
	}
  }while(option!=14);
  getch();
  return 0;
}

 void createlinkedlist( )   
 {
        int n,i,count=0;
	    struct node *newnode,*temp;
	    //head=0;//modified in code
	    printf("\nhow many data you want to enter:");
	    scanf("%d",&n);
	    temp=tail;
	   for(i=0;i<n;i++)
     	{
        	newnode=(struct node*)malloc(sizeof(struct node));
         	printf("\nenter data:");
	        scanf("%d",&newnode->data);
	        //newnode->next=0; //not ncessary
	        if(head==0) //this will execute only once because head=0; is declared so only first time condition will be true
	            {
	               tail=head=temp=newnode; //maintaining tail when there is one node if we dont write here tail then when there is only one node and we eneter 3 to insert at beginning that time error will produce because when only one node we try to access  tail->next=head; in insert at beginning func which is illegal so we have to write tail here   
             	}        
        	else
          	{
	           	temp->next=newnode;
		        tail=temp=newnode; //maintaining tail
	        }
        }
		newnode->next=head; //linking last node to head    //when there is only one node then also it will be circular link list
	    temp=head;
	    while(temp->next!=head)
	    {
		   printf("%d ",temp->data);
		   temp=temp->next;
		   count++;
	    }
	     printf("%d ",temp->data);
	  printf("\nNumber of nodes=%d",count+1);
	   	
 }	
 
  void displayallelement( )
  {
     if(head==0)//NULL
     {
     	printf("\nNo data list is empty.");
	 }
	 else
	 {
  	 struct node *temp;
  	 temp=head;
  	 printf("\nelements are:");
	    while(temp->next!=head)
	    {
	    	printf(" %d",temp->data);
		    temp=temp->next;
	    }
	    	printf(" %d",temp->data); //when temp->next!=head condition becomes false then this printf statement will execute to print the last node
     }
	  
  }
  
  void insertbeginning( )
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
	        newnode->next=head;//or newnode->next=tail->next  it contain address of head=tail->next if we want to use tail to access       //inserting newnode at beginning of list
	        head=newnode;      //or tail->next=newnode;  if we want to use tail to access
	        tail->next=head;  //making circular linked list connecting
	        printf("\nData after inserting at beginning:");
			temp=head;
	    while(temp->next!=head)
	    {
		   printf("%d ",temp->data);          //displaying the inserted node at beginning
		   temp=temp->next;
      	}
      	 printf("%d ",temp->data); 
     }
      	 
   }
   
    void insertatend() //we have to use void other wise error
   {
   	      if(head==0)//NULL
     {
     	printf("\nNo data list is empty.");
     	printf("\nenter 1 to create list");
	 }
	 else
	 {
	       struct node *newnode,*temp,*head;
   	        newnode=(struct node*)malloc(sizeof(struct node));
	    	printf("\nenter data to insert newnode at end of list:");
	        scanf("%d",&newnode->data);                                         //insertatend only using tail
   	         newnode->next=tail->next; //we putting starting address to newnode->next 
   	         tail->next=newnode;  //adding newnode at the end of CLL
				tail=newnode;     //maintaining the tail      
	        printf("\n\nData after inserting at end of list: ");
	        temp=head=tail->next; //now here temp and head is containing starting  addresss of circular linked list
	    while(temp->next!=head)
	    {
		   printf("%d ",temp->data);     //displaying the inserted node at end
		   temp=temp->next;
	    }
	     printf("%d ",temp->data); 
    	}
   }
   
   void insertatgivenposition( )
    {//1
    	
   	    if(head==0)//NULL
     {
     	printf("\nNo data list is empty.");
     	printf("\nenter 1 to create list");
	 }
	 else
	 {//2
	        struct node *newnode,*temp;
	        int pos,j=1,count=1;
            newnode=(struct node*)malloc(sizeof(struct node));
        	printf("\nenter position to insert :");
        	scanf("%d",&pos);
        	if(pos==1 || pos==0)//this should be here in circular link list to get the count of nodes exactly
        	{
        	  insertbeginning(head); //here we have maintain head node otherwise when we try to display node we will not get correct result	
			}
		else
			{//3
        	   temp=head;
        	   while(temp->next!=head)
        	    {
        	      temp=temp->next;  //counting number of nodes
			      count++;	
			    }
		     	if(pos>count)
			      {
			     	printf("\ninvalid position");
		           } 
		     	else
		     	{//4
			       temp=head;
				   while(j<pos-1)
				    {
				    	temp=temp->next;
						j++;  
			    	}
			    	newnode->next=temp->next;
			    	temp->next=newnode;		
			         printf("\nEnter data to insert:");
			         scanf("%d",&newnode->data);
		             temp=head;
	                 while(temp->next!=head)
	                 {
		               printf("%d ",temp->data);          //displaying the inserted node at given position
		               temp=temp->next;
	                 }
	                printf("%d ",temp->data);
		        }//4
	        }//3
	}//2
	   
	}//1
	
	 void  deletefrombegin( )
	 {
	 	if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
	 }
		else
	    {
	 	   displayallelement();
	       struct node *temp; 
		   if(head->next==head)//when there is only one node then only it will execute
	        {
	    	  free(head);
	    	  head=0;//this func will return head but when we free head what will this func return so we are assign head=0
	    	  tail=0;//no data so tail=0
	       	}
		   else
		    {
			   temp=head;
	           head=head->next;  
	           free(temp);
	           tail->next=head;// since first node is deleted  so only tail node is updated tail->next=head; which shows circular linked
	         }
	        printf("\nfirst node deleted successfully.\n");
	        printf("\nData after deleting first node from list.");
	        displayallelement();
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
		    struct node *prenode,*temp;
		    displayallelement();
			if(head->next==head)//when there is only one node then only it will execute
			{
				free(head);	
				head=0;//this func will return head but when we free head what will this func return so we are assign head=0 to return head=0
				tail=0;//no data so tail=0
		    }
			else
			{
				temp=head; 
		     	while(temp->next!=tail->next)
		     	{
			      prenode=temp;
			      temp=temp->next;	
			    }
			   prenode->next=head; 
			   tail=prenode;//since last node is deleted so maintaining last node
			   free(temp);	
			} 
			printf("\nLast node deleted successfully.");
			printf("\nData after deleting last node.");	
			displayallelement();
		 }
	 
	  }
	  void deletegivenposition( )
	  {
	  	if(head==NULL)
	 	{
	 		printf("\nNo data list is empty.");
		}
		else
		{
			struct node *nextnode,*temp;
			int i=1,pos,count=1;
			printf("\nEnter position to delete node:");
			scanf("%d",&pos);
		    temp=head;
		    while(temp->next!=head)
		    {
		    	temp=temp->next;
		    	count++;
			}
		    if(pos>count)
		    {
		    	printf("\ninvalid psition");
			}
			else
			{
		      if(pos==1 ||pos==0)
		      {
		      	deletefrombegin();
			  }
			  else if(pos==count)
			  {
			  	deletefromend();
			  }
		      else
			  {
				temp=head;
				 while(i<pos-1)
		        {
		           temp=temp->next;
			       i++;	
			    }
			    displayallelement(head);
		     	nextnode=temp->next;
			    temp->next=nextnode->next;
			    free(nextnode);
		     	printf("\nSelected position deleted successfully.");
		    	printf("\nData after deleting Selected position.");	
		    	displayallelement(); 
	          }
	      }
		}	 
	  }
	  
	   void reverse() //it also works when there is only one node
	   {
	   	  struct node *prevnode,*currentnode,*nextnode;
	   	 prevnode=tail; //first we have to set 	 prevnode=0 because first node is last node and last node does not not contin any address
	   	 currentnode=nextnode=head;
	   	 while(head!=currentnode->next )
	   	 {                             
	   	    nextnode=nextnode->next;    
		    currentnode->next=prevnode;
			prevnode=currentnode; //so that next node would contain the address of previous node
			currentnode=nextnode;
		  	 	
		 }
		   currentnode->next=prevnode;
		   tail=head;//maintaining tail 
		   head=currentnode;//maintaining head
		   displayallelement( );
	   }
	   
	    void sortinassendingorder( )
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
void removeduplicatesunsortedlist()//since it is singly circular linked list then we have to maintain tail because while creating list we are using tail
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
		
