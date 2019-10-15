#include <stdio.h>
#include <stdlib.h>
struct node{
		int data;
		struct node *link;
};
struct node *root = NULL;
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
	printf("Enter no\n\n");
	scanf("%d",&temp->data);
	temp->link = NULL;
	if(root==NULL)
	{
		root = temp;
	}
	struct node *p = root ;
	while(p!=NULL)
	{
		p = p->link;
	}
	 p->link = temp;

	/*	root = (struct node*)malloc(sizeof(struct node));
	printf("Enter no\n\n");
	scanf("%d",&temp->data);
	}
	else
	{
		struct node *p;
		p = root;
		while(p->link != NULL)
		{
			p = p->link;
		}
		//p->link = temp;
		p->link = (struct node*)malloc(sizeof(struct node));
	printf("Enter no\n\n");
	scanf("%d",&temp->data);
	}*/
	
}
void Insertatbegin()
{
	struct node *p;
	p = root;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the no\n");
	scanf("%d",&temp->data);
	temp->link = NULL;
	temp->link = p;
	root = temp;

}	
void Insertatafter()
{
	struct node *temp,*p;
	temp = root;
	int n,i=1;
	p = (struct node*)malloc(sizeof(struct node));
	printf("Enter the position after which you want to insert the data\n");
	scanf("%d",&n);
	if(n>Length())
	{
		printf("position doesn't exist\n");

	}
	else
	{
		printf("Enter the data \n");
		scanf("%d",&p->data);
		p->link = NULL;
		while(i<n)
		{
			i++;
			temp = temp->link;
		}
			p->link = temp->link;
			temp->link = p;
	}
	

}
int Length(void)
{
	int c = 0;
	struct node *temp;
	temp = root;
	
	if(temp == NULL)
	{
		printf("The list is empty\n");
		return 0;
	}
	else
	{
		while(temp != NULL)
			{
			c++;
			temp = temp->link;
			}
			return c;
	}
	
}
void Delete()
{
	struct node *temp;
	temp = root;
	int n;
	printf("Enter the position you want to Delete\n");
	scanf("%d",&n);
	int i = 1;
	int len;
	len = Length();
	if(n > len)
	{
		printf("Invalid position\n");
		printf("The list is containing %d elements\n",len );
	}
	else if( n == 1)
	{
		root = temp->link;
		temp->link = NULL;
		free(temp);

	}
	else
	{
		struct node *p,*q;
		p = temp;
		while(i<n-1)
		{
			i++;
			p = p->link;

		}
		q = p->link;
		p->link = q->link;
		q->link = NULL;
		free(q);

	}
}
void Display()
{
	struct node *temp;
	
	temp = root;
	while(temp != NULL)
	{
		printf("%d-->",temp->data );
		temp = temp->link;
	}
	printf("\n\n");
}