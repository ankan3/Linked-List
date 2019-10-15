#include <stdio.h>
#include <stdlib.h>
struct node{
		int data;
		struct node *left;
		struct node *right;
};
struct node *root = NULL;
struct node *tail = NULL;
int len;
void Insert(void);
void Insertatbegin(void);
void Insertatafter(void);
int Length(void);
void Delete(void);
void Display(void);
void main()
{
	int n;
	while(1)
	{
		printf("1. Insert \n");
		printf("2. Insert at begin \n");
		printf("3. Insert at after\n");
		printf("4. Length\n");
		printf("5. Delete  \n");
		printf("6. Display \n"); 
		printf("7. Quit\n");
		printf("\n\nEnter your choice\n");
		scanf("%d",&n);

		switch(n)
		{
			case 1: Insert();
				break;
			case 2: Insertatbegin();
				break;
			case 3: Insertatafter();
				break;
			case 4: len = Length();
					printf("Length is %d\n\n",len);
				break;
			case 5: Delete();
				break;
			case 6: Display();
				break;
			case 7: exit(1);
				break;
			default :printf("WRONG CHOICE\n\n");
		}
	}

}
void Insert()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	temp->right = NULL;
	temp->left = NULL;
	if (root == 0)
	{
		root = temp;
	}
	else
	{
		struct node *p;
		p = root;
		while(p->right !=NULL)
		{
			p = p-> right;
		}
		p->right = temp;
	}
}
void Insertatbegin()
{
	struct node *temp,*p;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	temp->right = NULL;
	temp->left = NULL;
	p = root;
	temp->right = p;
	root->left = temp;
	root = temp;

}
void Insertatafter()
{
	struct node *temp,*p;
	int n;
	p = root;
	printf("Enter the position after which you want to insert the data\n");
	scanf("%d",&n);
	int i = 1,l;
	if (n >  Length())
	{
		printf("Invalid location\n");
		printf("The list is contaning %d nodes \n",Length() );
	}
	else if (n==0)
	{
		printf("Please consider FIRST position as 1\n");
	}
	else if (n == Length())
	{
		struct node *temp,*p;
		temp = root;
		p = (struct node*)malloc(sizeof(struct node));
		printf("Enter data\n");
		scanf("%d",&p->data);
		p->right = NULL;
		p->left = NULL;
		while(temp->right != NULL)
		{
			temp = temp->right;
		}
		temp->right = p;
		p->left = temp;
	}
	else
	{
		printf("Enter node data\n");
		scanf("%d",&temp->data);
		temp->right = NULL;
		temp->left = NULL;
		while(i<n)
		{
			i++;
			p = p->right;

		}
		temp->right = p->right;
		p->right->left = temp;
		temp->left = p;
		p->right = temp;
	}
}
int Length()
{
	struct node *temp;
	temp = root;
	int c=0;
	if (temp == NULL)
	{
		printf("The list is empty\n");
		return 0;
	}
	else
	{
		while(temp!= NULL)
		{
			c++;
			temp = temp->right;
		}
		return c;
	}
}
void Delete()
{
	struct node *temp,*p;
	int n,i=1;
	temp = root;
	printf("Enter position \n");
	scanf("%d",&n);
	if (n>Length())
	{
		printf("Position doesn't exist \n");
		printf("The list contains %d elements\n",Length() );
	}
	else if (n==0)
	{
		printf("Please consider FIRST position as 1\n");
	}
	else if (n==1)
	{
		root = temp->right;
		temp->right->left = NULL;
		temp->right = NULL;

	}
	else if (n==Length())
	{
		while(i<n-1)
		{
			i++;
			temp = temp->right;

		}

		struct node *q = temp->right;
		temp->right = NULL;
		p -> left = NULL;
	}
	else
	{
		while(i<n-1)
		{
			i++;
			temp = temp->right;

		}

		struct node *p = temp->right;
		p->right->left = temp->right;
		temp->right = p->right;
		p->right = NULL;
		p->left = NULL;
		free(p);
	}

}
void Display()
{
	struct node *temp;
	temp = root;
	if (temp == NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		while(temp!= NULL)
		{
			printf("%d-->",temp->data);
			temp = temp->right;
		}
		printf("\n\n");
	}
}
