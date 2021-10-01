#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct sparshmatrix    //here  we make the code short but not extra node is created and printing extra garbage value
{                             //we have hoidden that garbage value by using temp->next==0 in printlist(head); function so we are getting right result but 1 node space is wasted
	int rowpos;
	int columnpos;
	int data;
	struct sparshmatrix *next;
}list;
//void representsparshmatrix(list**,list**,int,int,int);
void printlist(list *);
int main()
{
	int row,column;	
    int matrix[4][5]={{0 , 0 , 3 , 0 , 4 }, {0 , 0 , 5 , 7 , 0 }, {0 , 0 , 0 , 0 , 0 }, {0 , 2 , 6 , 0 , 0 }}; //inputs
	list *head=0;
	list  *newnode;
    head=newnode=(list*)malloc(sizeof(list));                  
	for(row=0;row<4;row++)
	{
		for(column=0;column<5;column++)
		 {
		     	if(matrix[row][column]!=0)   //directly representsparshmatrix
		    	{
                   newnode->rowpos=row;             //it works but one node space get wasted but to print right result then in this printlist(head); function 
   	               newnode->columnpos=column;         // we have to use temp->next==0 so that the 1 node which is extra created will be escape
	               newnode->data=matrix[row][column];  //so use this technique we have to know how many data are to be entered so we can break; to stop creating extra 1 node
	               newnode->next=(list*)malloc(sizeof(list));
	               newnode=newnode->next;
	               newnode->next=0;
		    	}
	     }
	}
printlist(head);
	getch();
	return 0;      
}

void printlist(list *head)
{
	list *row,*column,*data;
	row=column=data=head;   //here all is head so to print row column head individually
	printf("\nRow position:");
	while(row->next !=0)
	{
		printf(" %d",row->rowpos);
		row=row->next;
	}
	printf("\ncolumn position:");
		while(column->next!=0)
	{
		printf(" %d",column->columnpos);
		column=column->next;
	}
	printf("\nvalues:");
	while(data->next !=0)
	{
		printf(" %d",data->data);
		data=data->next;
	}
}

/*#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct sparshmatrix             //here we are using call by reference
{
	int rowpos;
	int columnpos;
	int data;
	struct sparshmatrix *next;
}list;
void representsparshmatrix(list**,list**,int,int,int);
void printlist(list *);
int main()
{
	int row,column;	
    int matrix[4][5]={{0 , 0 , 3 , 0 , 4 }, {0 , 0 , 5 , 7 , 0 }, {0 , 0 , 0 , 0 , 0 }, {0 , 2 , 6 , 0 , 0 }}; //inputs
	list *head=0,*tail=0;                  
	for(row=0;row<4;row++)
	{
		for(column=0;column<5;column++)
		{
			if(matrix[row][column]!=0)
			{
			  representsparshmatrix(&head,&tail,matrix[row][column],row,column); //creating sparsh matrix	
			}
		}
	}
printlist(head);
	getch();
	return 0;      
}
void representsparshmatrix(list** head,list** tail,int data,int row,int column)
{
   list *temp,*newnode;
   newnode=(list*)malloc(sizeof(list));
   newnode->next=0;
   temp=*head;
    
   if(temp==0)
   {
   	 newnode->rowpos=row;
   	 newnode->columnpos=column;
	 newnode->data=data;
	 *tail=temp=*head=newnode; 
   }
   else
   {
   	 temp=*tail;
   	 newnode->rowpos=row;
   	 newnode->columnpos=column;
	 newnode->data=data;
	 temp->next=newnode;
	 *tail=newnode;
   }	
}
void printlist(list *head)
{
	list *row,*column,*data;
	row=column=data=head;   //here all is head so to print row column head individually
	printf("\nRow position:");
	while(row!=0)
	{
		printf(" %d",row->rowpos);
		row=row->next;
	}
	printf("\ncolumn position:");
		while(column!=0)
	{
		printf(" %d",column->columnpos);
		column=column->next;
	}
	printf("\nvalues:");
	while(data!=0)
	{
		printf(" %d",data->data);
		data=data->next;
	}
}*/
/*#include<stdio.h>                  //difference to first code is here we are using  static list *head,*tail;
#include<stdlib.h>
#include<conio.h>
typedef struct sparshmatrix
{
	int rowpos;
	int columnpos;
	int data;
	struct sparshmatrix *next;
}list;
static list *head,*tail;
void representsparshmatrix(int,int,int);
void printlist(list *);
int main()
{
	int row,column;	
    int matrix[4][5]={{0 , 0 , 3 , 0 , 4 }, {0 , 0 , 5 , 7 , 0 }, {0 , 0 , 0 , 0 , 0 }, {0 , 2 , 6 , 0 , 0 }};                   
	for(row=0;row<4;row++)
	{
		for(column=0;column<5;column++)
		{
			if(matrix[row][column]!=0)
			{
			  representsparshmatrix(matrix[row][column],row,column);	
			}
		}
	}
printlist(head);
	getch();
	return 0;      
}
void representsparshmatrix(int data,int row,int column)
{
   list *temp,*newnode;
   newnode=(list*)malloc(sizeof(list));
   newnode->next=0;
   temp=head;
    
   if(temp==0)
   {
   	 newnode->rowpos=row;
   	 newnode->columnpos=column;
	 newnode->data=data;
	 tail=temp=head=newnode; 
   }
   else
   {
   	 newnode->rowpos=row;
   	 newnode->columnpos=column;
	 newnode->data=data;
	 tail->next=newnode;
	 tail=newnode;
   }	
}
void printlist(list *head)
{
	list *row,*column,*data;
	row=column=data=head;   //here all is head so to print row column head individually
	printf("\nRow position:");
	while(row!=0)
	{
		printf(" %d",row->rowpos);
		row=row->next;
	}
	printf("\ncolumn position:");
		while(column!=0)
	{
		printf(" %d",column->columnpos);
		column=column->next;
	}
	printf("\nvalues:");
	while(data!=0)
	{
		printf(" %d",data->data);
		data=data->next;
	}
}*/

//website code
/*  // C program for Sparse Matrix Representation  
// using Linked Lists 
#include<stdio.h> 
#include<stdlib.h> 
  
// Node to represent sparse matrix 
struct Node 
{ 
    int value; 
    int row_position; 
    int column_postion; 
    struct Node *next; 
}; 
  
// Function to create new node 
void create_new_node(struct Node** start, int non_zero_element, 
                     int row_index, int column_index ) 
{ 
    struct Node *temp, *r; 
    temp = *start; 
    if (temp == NULL) 
    { 
        // Create new node dynamically 
        temp = (struct Node *) malloc (sizeof(struct Node)); 
        temp->value = non_zero_element; 
        temp->row_position = row_index; 
        temp->column_postion = column_index; 
        temp->next = NULL; 
        *start = temp; 
  
    } 
    else
    { 
        while (temp->next != NULL) 
            temp = temp->next; 
  
        // Create new node dynamically 
        r = (struct Node *) malloc (sizeof(struct Node)); 
        r->value = non_zero_element; 
        r->row_position = row_index; 
        r->column_postion = column_index; 
        r->next = NULL; 
        temp->next = r; 
  
    } 
} 
  
// This function prints contents of linked list 
// starting from start 
void PrintList(struct Node* start) 
{ 
    struct Node *temp, *r, *s; 
    temp = r = s = start; 
  
    printf("row_position: "); 
    while(temp != NULL) 
    { 
  
        printf("%d ", temp->row_position); 
        temp = temp->next; 
    } 
    printf("\n"); 
  
    printf("column_postion: "); 
    while(r != NULL) 
    { 
        printf("%d ", r->column_postion); 
        r = r->next; 
    } 
    printf("\n"); 
    printf("Value: "); 
    while(s != NULL) 
    { 
        printf("%d ", s->value); 
        s = s->next; 
    } 
    printf("\n"); 
} 
  
  
// Driver of the program 
int main() 
{ 
   // Assume 4x5 sparse matrix 
    int sparseMatric[4][5] = 
    { 
        {0 , 0 , 3 , 0 , 4 }, 
        {0 , 0 , 5 , 7 , 0 }, 
        {0 , 0 , 0 , 0 , 0 }, 
        {0 , 2 , 6 , 0 , 0 } 
    }; 
  
    // Start with the empty list 
    struct Node* start = NULL; 
   int i,j;
    for(i = 0; i < 4; i++) 
        for (j = 0; j < 5; j++) 
  
            // Pass only those values which are non - zero 
            if (sparseMatric[i][j] != 0) 
                create_new_node(&start, sparseMatric[i][j], i, j); 
  
    PrintList(start); 
  
    return 0; 
} */
