#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct  node *next;
}node;
node *p,*q,*next;

node *create(node *);
void display(node *);
void search(node *);
node delete(node *);
node *insert(node *);

void main()
{	int ch;
	node *start;
	while(1){
	printf("\n Menu:\n 1.create \n 2.display \n 3.insert \n 4.delete \n 5.search \n 6.exit \n");
	  printf("Enter your choice:\n");
	  scanf("%d",&ch);
	  
	switch(ch){
		case 1:start=create(start);
			break;
		case 2:display(start);
			break;
		case 3:start=insert(start);
			break;
		case 4:delete(start);
			break;
		case 5:search(start);
			break;
		case 6:exit(0);
		default:printf("\n Invalid choice");
			break;
	}
      }
}


node *create(node *start)
{	int i,n;
	node *p;
//	start=NULL;
	printf("Enter the no of elements to store:\n");
	scanf("%d",&n);
	start=(node *)malloc(sizeof(node));
	printf("Enter the data of first node:\n");
	scanf("%d",&start->data);
	start->next=NULL;
	p=start;
	for(i=1;i<n;i++)
	{	p->next=(node *)malloc(sizeof(node));
		p=p->next;
		printf("Enter data of next node:\n");
		scanf("%d",&p->data);
		p->next=NULL;	
	}
	return (start);
}

void display(node *start)
{	node *p;
	p=start;
	if(start==NULL)
  	  printf("\n List is Empty \n");
	else{
	  while(p!=NULL)
	  {	printf("%d->",p->data);
		p=p->next;
	  }
	}
}

node *insert(node *start)
{	node *p,*q;
	int i,ch,loc;
	p=(node *)malloc(sizeof(node));
	printf("\n Enter the data to be inserted:");
	scanf("%d",&p->data);
	p->next=NULL;
	printf("\n Choices for insertion \n 1. at start \n 2. at end \n 3. at location");
	printf("\n Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{ 	case 1: p->next=start;
			start=p;
			display(start);
			break;
		case 2: q=start;
			while(q->next!=NULL)
			{	q=q->next;
			}
			q->next=p;
			display(start);
			break;
		case 3: printf("Enter the location:");
			scanf("%d",&loc);
			q=start;
			for(i=1;i<loc-1;i++)
				q=q->next;
			p->next=q->next;
			q->next=p;
			display(start);
			break;
	}
	return (start);
}

void search(node *start)
{	int temp,flag=0,loc=1;
	node *p,*q;
	printf("\n Enter the data to be searched:");
	scanf("%d",&temp);
	q=start;
	while(q!=NULL && flag==0)
	{	if(q->data==temp)
		   flag=1;
		else
		 {	q=q->next;
			loc++;
		 }
	}
	if(flag==0)
		printf("\n Data not found");
	else
		printf("\n Found at %d location", loc);
}

node delete(node *start)
{	int i,loc,ch;
	node *p,*q;
	if(start==NULL)
	   printf("\n List is empty");
	else
	{
	printf("\n Choices for deletion are:");
	printf("\n 1.From start \n 2.from end \n 3.From location");
	printf("\n Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{	case 1: p=start;
			start=p->next;
			p->next=NULL;
			free(p);
			display(start);
			break;
		case 2: p=start;
			q=p->next;
			while(q->next!=NULL)
			   {	p=p->next;
				q=q->next;
			   }
			p->next=NULL;
			free(q);
			display(start);
			break;
		case 3: printf("\n Enter the location:");
			scanf("%d",&loc);
			p=start;
			for(i=1;i<loc-1;i++)
				p=p->next;
			q=p->next;
			p->next=q->next;
			free(q);
			display(start);
			break;
		}
	}
}














