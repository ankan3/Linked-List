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
void transverse()
{
	struct node *temp = head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data );
		temp = temp->next;
	}

}
void transverseReverse(struct node *temp)
{
	if (temp == NULL)
	{
		return;
	}
	transverseReverse(temp->next);
	printf("%d\n",temp->data);

}
int main()
{
	insertFirst(20);
	insertFirst(30);
	insertFirst(40);
	insertFirst(50);
	insertFirst(60);
	transverse();

	printf("rever transverse\n");
	transverseReverse(head);
}
