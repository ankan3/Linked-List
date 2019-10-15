#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data ;
	struct node *next;

};

struct node *head =NULL;
struct node* newNode(int data)
{
	struct node *new = (struct node*) malloc(sizeof(struct node ));
	new->data = data;
	new->next = NULL;

}
void insertFirst(int data)
{
	struct node *new = newNode(data);
	if (head == NULL)
	{
		head = new;
		return;
	}
	new->next = head;
	head = new;

}
//int k;
static int m=1;
void transverseReverse(struct node *temp,int k)
{
	//static int m=1;
	if (temp == NULL)
	{
		return;
	}


	
	
	transverseReverse(temp->next,k);
	//printf("%d\n",temp->data );
	
	
	if (k == m)
	{
		
		//printf("%d\n",temp->data);
		printf("%d\n", temp->data);
	}
	m = m+1;

}
void printnode()
{
	struct node *temp = head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data );
		temp = temp->next;
	}


}



int main()
{
	int n;
	printf("enter the size of list\n");
	scanf("%d",&n);
	int data;
	printf("enter elements in list\n");
	int i;
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&data);
		insertFirst(data);

	}
	printf("enter the value of m\n");
	int k;
	scanf("%d",&k);
	printf("list are\n");
	printnode();
	transverseReverse(head,k);

}
