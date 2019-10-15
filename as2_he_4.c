#include<stdio.h>
#include<stdlib.h>

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

void deleteFirst()
{
	if (head == NULL)
	{
		printf("no node contain in the memory\n");
		return;
	}
	head = head->next;
}
int length()
{
	struct node *temp = head;
	int len = 0;
	if (head == NULL)
	{
		return 0 ;
	}

	while (temp!=NULL)
	{
		temp = temp->next;
		len++;
	}
	return len;
}

void delete(struct node *temp)
{
	int p =1;
	struct node *temp1 = head->next,*prev;
	while(temp1!=NULL)
	{
		if (temp1->data == temp->data)
		{
			break;	/* code */
		}
		p++;
	}
	//if (p==1)
	//{
	//	deleteFirst();
	//	return;
		/* code */
//	}
	if (p==length())
	{
		deleteLast();
		return;
		/* code */
	}
	temp1 = head;
	while(temp!= temp1)
	{
		prev = temp1;
		temp1 = temp1->next;
	}

	prev->next = temp1->next;

}

void dublicate()
{
	int i;
	struct node *temp = head;
	struct node *temp2 ;
	if (head == NULL)
	{
		printf("no element in list\n");
		return;
		/* code */
	}
	if (length() == 1)
	{
		printf("no dublicate item\n");
		/* code */
	}
	for (;temp->next !=NULL; temp=temp->next)
	{
		if (length() == 1)
		{
			return;
		}
		struct node *prev = temp;
		for (temp2 = temp->next; temp2!=NULL ; temp2 = temp2->next)
		{
			if ((temp2->data == temp->data) && (temp2->next == NULL))
			{
				deleteLast();
				break;
			}

			if (temp2->data == temp->data)
			{
				prev->next = temp2->next;
				temp2 = prev;
			}
			prev = temp2;

			
		}

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
	insertLast(10);
	insertLast(20);
	insertLast(10);
	insertLast(10);
	insertLast(30);
	insertLast(10);
	printhh();
	printf("after dublicate remove\n");
	//printhh();
	dublicate();
	printhh();

	int n,i,element;
	printf("enter the size os list\n");
	scanf("%d",&n);
	printf("enter the element of list\n");
	for ( i = 0; i < n; ++i)
	{	scanf("%d",&element);
		insertLast(element);
	}
	printhh();
	printf("after dublicate remove\n");
	//printhh();
	dublicate();
	printhh();

}
