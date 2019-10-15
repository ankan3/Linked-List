#include <stdio.h>
#include <stdlib.h>
struct node{
			int data;
			int *link;
};
struct node* root = NULL;
int len;
void insert(void);
int length(void);
void display(void);
void main()
{
	int ch;
	while(1)
	{
		printf("1. insert\n");
		printf("2. display\n");
		printf("3. length\n");
		printf("4. exit\n");
		printf("\n\n");
		printf("Enteryour choice\n");
		scanf("%d",&ch);
	
	//scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					insert();
					break;
			case 2:
					display();
					break;
			case 3:
					len = length();
					printf("Length is %d\n\n",len );
					printf("\n\n");
					break;

			case 4:
					exit(1);
					break;
			default :
				printf("your choice is wrong\n\n");		
		}
	}

}
	void insert(void)
	{
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter the data\n\n");
		scanf("%d",&temp->data);
		temp->link=NULL;
		if(root==NULL)
		{
			root = temp;
		}
		else
		{
			struct node *p;
			p = root;
			while(p->link!=NULL)
			{
				p = p->link;
			}
			p->link = temp;
		}
	}
	int length(void)
	{
	int	count=0;
	struct node *temp;
	temp=root;
	if(temp==NULL)
		{
			printf("Node is empty\n\n");
			return 0;

		}
	else
		{
			while(temp!=NULL)
			{
				count++;
				temp=temp->link;
			}
			return count;
		}
		//printf("Length is %d\n\n",count);
	}
	void display(void)
	{
		struct node *temp;
		temp = root;
		if(temp==NULL)
			{
			printf("Node is empty\n\n");

			}
		else
		{
			while(temp!=NULL)
			{
				printf("%d-->",temp->data );
				temp=temp->link;
			}
			printf("\n\n");
		}
	
	}