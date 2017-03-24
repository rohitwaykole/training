#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;
node *top,*p,*temp;

node *push(node *);
node *pop(node *);
void display(node *);

void main(){
	int ch;
	node *top,*temp;
	top = NULL;
	while(1){
		printf("\n Menu \n 1.Push \n 2.Pop \n 3.Display \n 4.Exit");
		printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: top = push(top);
				break;
			case 2: top = pop(top);
				break;
			case 3: display(top);
				break;
			case 4: exit (0);
			default: printf("Invalid choice");
				break;
			}
		}
}

node *push(node *top)
{	
	int ch;
	node *p;
	{
		p=(node *)malloc(sizeof(node));
		printf("Enter the data to be pushed:");
		scanf("%d",&p->data);
		p->next=NULL;
		if (top == NULL)
			top = p;
		else
		{	p->next=top;
			top=p;
		}
	}
	printf("\n do you want to add more?(y/n)");
	scanf("%d",&ch);
//	if(ch == 'y')
//		push(top);
		
}

node *pop(node *top)
{
  	int x;
  	node *temp;
  	if(top == NULL)
   		printf("\n Stack empty");
  	else
  	{
		x = top->data;
		temp = top;
		top = top->next;

		free(temp);
		printf("\n Element %d is popped out",x);
  	}
  	return(top);
}	

void display(node *top)
{
	if(top == NULL)
		printf("\n stack is empty!");
	else
	{	p=top;
		while(p!= NULL)
		{	
			printf("%d",p->data);
			p = p->next;
		}
		
	}	
}	
