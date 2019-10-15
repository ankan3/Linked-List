#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};

struct node *head;
void insertLast( int item)
{
	struct node *new = (struct node*) malloc(sizeof(struct node));
	new->data = item;
	new->next = NULL;
	if (head == NULL)
	{
		head = new;
		return;
	}

	struct node *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = new;
}

void insertFirst(struct node *new)
{
	if (head == NULL)
	{
		head = new;
		return;
	}

	new->next = head;
	head = new;
}

void insert( int data)
{

	struct node *temp = head;
	struct node *prev = NULL;
	if (head ==NULL)
	{
		return;
		/* code */
	}
	if (data <= temp->data)
	{
		insertFirst(data);
		return;
	}
	struct node *new = (struct node*) malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	prev = temp;
	temp = temp->next;

	while (temp->next != NULL)
	{
		prev = temp;
	    temp = temp->next;
	    if ((data > prev->data) && (data <= temp->data))
	    {
	    	prev->next = new;
	    	new->next = temp;
	    	return;

	    }


	}
	if (data >= temp->data)
	{
		/* code */
		insertLast(data);
	}

}
void printhh()
{
	struct node *temp = head;
	if (head == NULL)
	{
		printf("sjio\n");
		return;
		/* code */
	}
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

int main()
{
	int n,i,element;
	printf("enter the size os list\n");
	scanf("%d",&n);
	printf("enter the element of list in ascending order\n");
	for ( i = 0; i < n; ++i)
	{	scanf("%d",&element);
		insertLast(element);
	}
	printhh();
	int data;
	printf("enter the data to be inserted\n");
	scanf("%d",&data);
	insert(data);
	printhh()
}
