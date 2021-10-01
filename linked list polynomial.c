#include<stdio.h> //this program solve only first line
#include<stdlib.h>//this is for malloc function
#include<conio.h>
struct node
{
	 int coefficient,exponent;
	struct node *next;
};
static struct node *firstpolyhead=0,*firstpolytail=0,*secondpolyhead=0, *secondpolytail=0;//no need to initialize to 0 because global varialbe contain 0
void Createpolynomial();
void displaypolynomial();
void additionofpolynomial();
int main ()
{
	int option;
	do
	{
		printf("\n\n******MAIN MENU*********");
	    printf("\n1.Create polynomial.");
		printf("\n2.Display polynomial.");
		printf("\n3.Add the polynominals.");
		printf("\n\nEnter the option.");
		scanf("%d",&option);
		switch(option)
		{
			case 1:Createpolynomial();
				break;
			case 2:displaypolynomial();
				break;
			case 3:additionofpolynomial();
			    break;
		}
	}while(option<=3);
	getch();
	return 0;	
}
 
 void Createpolynomial()
 {
 	 firstpolyhead=firstpolytail=secondpolyhead=secondpolytail=0;
     //all are set to zero so that when this Createpolynomial() func execute for second time it will start to take new ponynomial
 	int n=1;
   	struct node *newnode,*temp,*duplicatefirstpolytail,*duplicatefirstpolyhead;
	printf("\nEnter co-efficient 0 to stop entering terms."); 
	printf("\nEnter first polynomial.\n");
	while(n<=2) 
	{//1
		if(n==2)
		{
	    	printf("\nEnter second polynomial.");
            printf("\nEnter co-efficient 0 to stop entering terms.\n");
		}
		while(n>0)
		{//2
		 newnode=(struct node*)malloc(sizeof(struct node));
   	     if(firstpolyhead==NULL)
   	      {
   	      	printf("\nEnter Co-efficient ");
   	        scanf("%d",&newnode->coefficient);
   	        if(newnode->coefficient== 0)
   	        {
   	        	break;//terminate 2 while loop to enter second polynomial and it should be hare
			}
   	        printf("\nEnter Exponent ");
   	        scanf("%d",&newnode->exponent);
   	        newnode->next=0;
   	        temp=firstpolytail=firstpolyhead=newnode; 
          }
         else
          {
       	    printf("\nEnter Co-efficient ");
   	        scanf("%d",&newnode->coefficient);
   	        if(newnode->coefficient== 0)
   	        {
   	        	break; //terminate 2 while loop
		    }
   	        printf("\nEnter Exponent ");
   	        scanf("%d",&newnode->exponent);
   	        newnode->next=0;
   	        temp->next=newnode;
   	        temp=firstpolytail=newnode; 
	      }
	   }//2
	   if(n==1)
	   {
	   	duplicatefirstpolyhead=firstpolyhead;  //after entering first polynomial we are exchanging head and tail so second polynomial start with 0
	    duplicatefirstpolytail=firstpolytail;
	    firstpolyhead=secondpolyhead; //here starting with 0
	    firstpolytail=secondpolytail;
	   }
	   else//n==2
	   {
	   	secondpolyhead=firstpolyhead;  //since first polynomial contain address of second polynomial so address is assigned to second polynomial
	   	secondpolytail=firstpolytail;
	   	firstpolyhead=duplicatefirstpolyhead;// we are giving address of first polynomial
	   	firstpolytail= duplicatefirstpolytail;// we are giving address of first polynomial
	   	break;
       }
	   n++;  
    }//1	  
 }
 void displaypolynomial()
 {
 	struct node *temp;
 	int i=1;
 	temp=firstpolyhead;
 	printf("\nFirst Polynomial= ");
 	while(i<=2)//due to two polynomial it will execute two times
 	{
 		if(i==2)
 		{
 				printf("\n\nSecond Polynomial= ");
		 }
 		while(temp!=0)
 		{
 	     printf(" %dx^%d ",temp->coefficient,temp->exponent);
	     temp=temp->next;
	     if(temp!=0)
	     {
	   	 if(temp->coefficient>0)
	   	 {
	   	 	printf("+");
		 }
		 else
		 {
		   	printf("");	
		 }
	     }
	   }
	temp=secondpolyhead;
	i++;	
 }
}
void additionofpolynomial()
{
   displaypolynomial();
   struct node *storeresultaddition,*firstpoly,*secondpoly,*r;
   firstpoly=firstpolyhead;
   secondpoly=secondpolyhead;
   r=storeresultaddition=(struct node*)malloc(sizeof(struct node));
   while(firstpoly!=0 && secondpoly!=0)
   {
   	 if(firstpoly->exponent==secondpoly->exponent)
   	 {
   	   storeresultaddition->coefficient=firstpoly->coefficient+secondpoly->coefficient;
   	   storeresultaddition->exponent=firstpoly->exponent;
   	   firstpoly=firstpoly->next;
	   secondpoly=secondpoly->next;  	
	 }
	 else if(firstpoly->exponent>=secondpoly->exponent)
	 {
	   storeresultaddition->coefficient=firstpoly->coefficient;
   	   storeresultaddition->exponent=firstpoly->exponent;
   	   firstpoly=firstpoly->next;
	 }
	 else if(firstpoly->exponent<=secondpoly->exponent)
	 {
	   storeresultaddition->coefficient=secondpoly->coefficient;
   	   storeresultaddition->exponent=secondpoly->exponent;
   	   secondpoly=secondpoly->next;
	 }
	  if(firstpoly==0 && secondpoly==0)//when two polynomial cotain same no of terms so sometimes both becomes 0 so for that no extra space will be created by this  storeresultaddition->next so break is used
       { 
	     break;
	   }
	 storeresultaddition->next=(struct node*)malloc(sizeof(struct node));  //new concept
	 storeresultaddition=storeresultaddition->next;
	 storeresultaddition->next=0;
   }
    while(firstpoly || secondpoly)
	{
		if(firstpoly!=0)
		{
	      storeresultaddition->coefficient=firstpoly->coefficient;
   	      storeresultaddition->exponent=firstpoly->exponent;
   	      firstpoly=firstpoly->next;
       } 
    	if(secondpoly!=0)
	   {
	     storeresultaddition->coefficient=secondpoly->coefficient;
   	     storeresultaddition->exponent=secondpoly->exponent;
   	     secondpoly=secondpoly->next;
       }
       if(firstpoly==0 && secondpoly==0)//so that no extra space will be created by this  storeresultaddition->next when both becomes 0
       { 
	     break;
	   }
	  storeresultaddition->next=(struct node*)malloc(sizeof(struct node));  //new concept
	  storeresultaddition=storeresultaddition->next;
	  storeresultaddition->next=0;
    }
     printf("\n\nAfter adding the polynomials.");
	 while(r!=0)//r contain base address of result 
	 {
	 	printf(" %dx^%d",r->coefficient,r->exponent);
	 	r=r->next;
	 if(r!=0)
	     {
	   	 if(r->coefficient>0)
	   	 {
	   	 	printf(" +");
		 }
		 else
		 {
		   	printf("");	
		 }
    	}
	 }
	 
}

/*#include<stdio.h>   // it also works properly it solve only first line
#include<malloc.h>
#include<conio.h>       
struct link{
       int coeff;
       int pow;
       struct link *next;
       };
struct link *poly1=NULL,*poly2=NULL,*poly=NULL;
void create(struct link *node)
{
 char ch;
 do
 {
  printf("\n enter coeff:");
  scanf("%d",&node->coeff);
  printf("\n enter power:");
  scanf("%d",&node->pow);
  node->next=(struct link*)malloc(sizeof(struct link));
  node=node->next;
  node->next=NULL;
  printf("\n continue(y/n):");
  ch=getch();
 }
 while(ch=='y' || ch=='Y');
}
void show(struct link *node)
{
 while(node->next!=NULL)
 {
  printf("%dx^%d",node->coeff,node->pow);
  node=node->next;
  if(node->next!=NULL)
   printf("+");
 }
}
void polyadd(struct link *poly1,struct link *poly2,struct link *poly)
{
     while(poly1->next &&  poly2->next)
     {
      if(poly1->pow>poly2->pow)
      {
       poly->pow=poly1->pow;
       poly->coeff=poly1->coeff;
       poly1=poly1->next;
       }
      else if(poly1->pow<poly2->pow)
      {
       poly->pow=poly2->pow;
       poly->coeff=poly2->coeff;
       poly2=poly2->next;
       }
      else
      {
       poly->pow=poly1->pow;
       poly->coeff=poly1->coeff+poly2->coeff;
       poly1=poly1->next;
       poly2=poly2->next;
       }
      poly->next=(struct link *)malloc(sizeof(struct link));
      poly=poly->next;
      poly->next=NULL;
     }
     while(poly1->next || poly2->next)
     {
      if(poly1->next)
      {
       poly->pow=poly1->pow;
       poly->coeff=poly1->coeff;
       poly1=poly1->next;
       }
      if(poly2->next)
      {
       poly->pow=poly2->pow;
       poly->coeff=poly2->coeff;
       poly2=poly2->next;
       }
       poly->next=(struct link *)malloc(sizeof(struct link));
       poly=poly->next;
       poly->next=NULL;
       }
}
main()
{
      char ch;
      do{
      poly1=(struct link *)malloc(sizeof(struct link));
      poly2=(struct link *)malloc(sizeof(struct link));
      poly=(struct link *)malloc(sizeof(struct link));
      printf("\nenter 1st number:");
      create(poly1);
      printf("\nenter 2nd number:");
      create(poly2);
      printf("\n1st Number:");
      show(poly1);
      printf("\n2nd Number:");
      show(poly2);
      polyadd(poly1,poly2,poly);
      printf("\nAdded polynomial:");
      show(poly);
      printf("\n add two more numbers:");
      ch=getch();
      }
      while(ch=='y' || ch=='Y');
}*/
