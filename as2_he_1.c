#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;

};
struct node *head = NULL;
void insertlast(int item)
{
	struct node *new = (struct node*) malloc(sizeof(struct node));
	new->data =item;
	new->next = NULL;
	struct node *temp = head;
	if (head == NULL)
	{
		head = new;
		return;
		/* code */
	}

	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = new;
	printf("ec\n");



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
void deleteFirst()
{
	if (head == NULL)
	{
		printf("no node contain in the memory\n");
		return;
	}
	head = head->next;
}
void deleteLast()
{
	if (head == NULL)
	{
		printf("no node contain in the memory\n");
		return;
	}
	struct node *temp = head;
	struct node *prev = NULL;
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;

}

void search(int item)
{
	if (head == NULL)
	{
		printf("no item in the memory\n");
		return;
	}

	struct node *temp = head;
	struct node *prev = NULL;
	while(temp->next!=NULL)
	{
		if (item == head->data)
		{
			printf("item found\n");
			//insertFirst(temp);
			deleteFirst();
			printf("element found at first\n");
			return;

		}
		if (item == temp->data)
		{
			printf("element found\n");
			prev->next = temp->next;
			insertFirst(temp);
			return;
		}
		prev = temp;
		temp = temp->next;


	}
	printf("%d\n",temp->data );

	if (temp->data == item)
	{	
		deleteLast();
		insertFirst(temp);
		return;
	}
	printf("element not found\n");

}
void printNode()
{
	struct node *temp = head;
	if (temp==NULL)
	{
		printf("no node\n");
		return;
		/* code */
	}
	while(temp!=NULL)
	{
		printf("%d\n",temp->data );
		temp = temp->next;
	}
}


void main()
{
	int n,i,data,s;
	printf("enter the size of list\n");
	scanf("%d",&n);
	printf("enter the elements \n");
	for ( i = 0; i < n; ++i)
	{
		/* code */
		scanf("%d",&data);
		insertlast(data);
	}
	printf("list are\n");
	printNode();
	printf("enter elements to be searched\n");
	scanf("%d",&s);
	search(s);
	printf("list is\n");
	printNode();


	/*insertlast(1);
	insertlast(2);
	insertlast(3);
	insertlast(4);
	insertlast(5);
	insertlast(6);
	printf("before search\n");
	printNode();
	search(6);
	//deleteLast();
	printf("after serch\n");
	printNode();*/

}