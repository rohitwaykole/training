#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
}node;

node *create(node *);
void display(node *);
//void search(node *);
//node delete(node *);
node *insert(node *);

void main()
{       int ch;
        node *head = NULL;
	node *tail = NULL;
        while(1){
        printf("\n Menu:\n 1.create \n 2.display \n 3.insert \n 4.delete \n 5.search \n 6.exit \n");
          printf("Enter your choice:\n");
          scanf("%d",&ch);

        switch(ch){
                case 1:head = create(head);
                        break;
                case 2:display(head);
                        break;
                case 3:head = insert(head);
                        break;
       //         case 4:delete(start);
       //                 break;
       //         case 5:search(start);
       //                 break;
                case 6:exit(0);
                default:printf("\n Invalid choice");
                        break;
        }
      }
}

node *create(node *head)
{
	int i,n;
	node *p,*q;
	printf("Enter the no of elements to store:\n");
        scanf("%d",&n);
	head = (node *)malloc(sizeof(node));
	printf("enter the value:");
	scanf("%d",&head->data);
	head->prev = NULL;
	head->next = NULL;
	p=head;
        for(i=1;i<n;i++)
        {       p->next=(node *)malloc(sizeof(node));
                q=p;
		p=p->next;
                printf("Enter data of next node:\n");
                scanf("%d",&p->data);
                p->next=NULL;
		p->prev=q;
        }
        return (head);

}

void display(node *head)
{
	node *p;
	if ( head == NULL)
  		printf("Empty\n");
 	else {
		p = head;
		while(p != NULL )
		{	printf("->%d",p->data);
			p = p->next;
		}
	}
}

node *insert(node *head)
{	node *p,*q,*tail,*temp;
        int i,ch,loc,n;
        p=(node *)malloc(sizeof(node));
        printf("\n Enter the data to be inserted:");
        scanf("%d",&n);
	p->data = n;
        p->next=NULL;
	p->prev = NULL;
        printf("\n Choices for insertion \n 1. from head \n 2. from tail \n 3. at location from head");
        printf("\n Enter your choice:");
        scanf("%d",&ch);
	switch(ch)
	{
		case 1: p->next = head;
			head->prev = p;
			head = p;
			display(head);
			break;
		case 2: q = head;
			while ( q->next != NULL )
			{
				q = q->next;
			}
			q->next = p;
			p->prev = q;
			tail = p;
		
			
			display(head);
			break;
		case 3: printf("Enter the location:");
			scanf("%d",&loc);
			q = head;
			for(i=1;i<loc-1;i++)
				q = q->next;
			temp = q->next;
			q->next = p;
			p->prev = q;
			p->next = temp;
			temp->prev = p;
			display(head);
			break;
		

		default:printf("invalid choice");
			break;
	}
}
		
	













