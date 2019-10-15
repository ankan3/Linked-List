#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;

};

struct node *head = NULL;

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

void reverse(struct node *temp,int m)
{
	static int i;
	if (temp == NULL)
	{
		return;
	}
	reverse(temp->next,m);
	if (i!=m)
	{
		/* code */
		printf("%d\n",temp->data );
		i++;
	}
	

}
int main()
{
	int n,i,m,element;
	printf("enter the size os list\n");
	scanf("%d",&n);
	printf("enter the element of list\n");
	for ( i = 0; i < n; ++i)
	{	scanf("%d",&element);
		insertLast(element);
	}
	printf("enter the position from last you want to print\n");
	scanf("%d",&m);
	//insertLast(1);
	//printf("executed\n");
	//insertLast(2);
	//insertLast(3);
	//insertLast(4);
	//insertLast(5);
	//insertLast(6);
	//printf("executed\n");
	printhh();
	printf("list after reversing till  %d\n",m);
	reverse(head,m);

}
