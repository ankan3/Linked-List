//Grounded Header Link List
#include <stdio.h>
#include <malloc.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;

/*struct node**/void create();
/*struct node**/void display();

int main()
{
  int option;
  do
  {
 
   {
    case 1:
      create();
      printf("\n Header Linked List Created Successfully");
      break;
    case 2:
      display();
      break;
   }
  }while(option != 3);
 return 0;
}

//Create the Grounded Header Link List
void create()
{
  struct node *new_node, *ptr, *hn;
  int num;
  printf("\n Enter -1 to end");
  printf("\n Enter the data :");
  scanf("%d", &num);
 

//Create the Grounded Header Link List
void display()
{
  struct node *ptr;
  ptr = head;
  ptr = ptr -> next;
  while(ptr != NULL)
  {
    printf("\t %d",ptr -> data);
    ptr = ptr -> next;
  }
}


