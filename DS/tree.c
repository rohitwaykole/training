#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *left,*right;
}node;
node *root,*newnode,*temp,*parent;

void create();
void inorder(node*);
void preorder(node*);
void postorder(node*);
void search();


void main()
 {
  int ch,n; 
  root=NULL; 
  while(1)
  {
   printf("\n The menu is:");
   printf("\n1.create\n2.Inorder\n3.Preorder\n4.postorder\n6.search\n6.exit");
   printf("\n Enter your choice");
   scanf("%d",&ch);
   switch(ch)
    {
	case 1:create();
	break;
	case 2:printf("\n Inorder traversal of tree is:");
	inorder(root);
	break;
	case 3:printf("\n Preorder traversal of tree is:");
	preorder(root);
	break;
	case 4:printf("\n Postorder traversal of tree is:");
	postorder(root);
	break;
	case 5:search();
	break;
	case 6:exit(0);
	default:printf("\n Wrong choice:");
	break;
    }
  }
}

void create()
{
   int n;
      
 
	printf("\n Enter the data to be inserted:");
	scanf("%d",&n);
	newnode=(node *)malloc(sizeof(node)); 
	newnode->data=n;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	  root=newnode;
	else
	{
	  temp=root;
	  while(temp != NULL){
	  if(temp->left == NULL)
		{		temp->left = newnode;
	//			temp = temp->left;
		}
		
	  else{
		temp->right = newnode;
	//	temp = temp->right;
	}
      }
   }
}

void inorder(node *temp) 
{
	if(temp!=NULL)
	{
	  inorder(temp->left);
	  printf("\t%d",temp->data);
	  inorder(temp->right);
	}
}


void preorder(node *temp)
{
	if(temp!=NULL)
	{
	  printf("\t%d",temp->data);
	  preorder(temp->left);
	  preorder(temp->right);
	}
}

void postorder(node *temp)
{
	if(temp!=NULL)
	{
	  postorder(temp->left);
	  postorder(temp->right);
	  printf("\t%d",temp->data);
	}
}

void search()
	{
	int key,flag=0;
	printf("\n Enter the element to be searched:");
	scanf("%d",&key);
	temp=root;
	while(temp!=NULL)
	 {
	  if(temp->data==key)
		{
		flag=1;
		break;
		}
	else
		{
		if(key<temp->data)
		temp=temp->left;
		else
		temp=temp->right;
		}
	}
	if(flag==1)
		printf("\n Element found");
	else
		printf("\n Element not found");
	}

