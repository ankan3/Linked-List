#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};

int occurence(int data)
{
	struct node *temp = head;
	int count;
	if (head == NULL)
	{
		printf("no node contain in memory\n");
		return;
		/* code */
	}
	while(temp!=NULL)
	{
		if (temp->data == data)
		{
			count++;
		}

	}
	return count;

}

int main()
{
	int n,i,data;
	printf("enter the size of list\n");
	scanf("%d",&n);
	printf("enter the elements \n");
	for ( i = 0; i < n; ++i)
	{
		/* code */
		scanf("%d",&data)
		insertlast(data);
	}

}
