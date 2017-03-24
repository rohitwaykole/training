#include<stdio.h> 
#include<stdlib.h>

 typedef struct node
 {
        int data;
        struct node* next;
 }node;
node *rear, *front;

int enqueue(int );
void dequeue();
void display();


int main()
{
     int i=0,value;
     rear=front=NULL;
     
     while(1){
     printf(" \n1. Enqueue");
     printf(" \n2. Dequeue");
     printf(" \n3. Display Data of Queue");
     printf(" \n4. Exit\n");
     printf(" \nChoose Option: ");
     scanf("%d",&i);
     switch(i){
		case 1:
                     printf("\nEnter a value to push into Queue: ");
                     scanf("%d",&value);
                enqueue(value); 
                     display();
                     break;
		case 2: dequeue();
			display();
			break;
		case 3:display();
			break;
		case 4:exit (0);
		default:printf("Invalid choice");
	}
     }
	return 0;
}

int  enqueue(int val)
{
     struct node *temp;
    
     if ( rear == NULL)
	{	temp = (node *)malloc(sizeof(node));
		temp->data=val;
		rear = temp;
		rear->next = NULL;
		front = rear;
	}
     else
	{
		temp = (node *)malloc(sizeof(node));
		temp->data = val;
		temp->next = NULL;	
		rear->next = temp;
		rear = temp;
		
	}

}

void dequeue()
{
     
node *temp;
      if (front == NULL )
	printf("Empty");
      else
      {	     
	     temp = front;
             front=front->next;
             free(temp);
      }
}


void display()
{
     struct node *temp=front;
     if(temp!=NULL)
     {
           printf("\nElements are as:  ");
           while(temp!=NULL)
           {
                printf("\t%d",temp->data);
                temp=temp->next;
           }
     printf(" \n");
     } 
}		
