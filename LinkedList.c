#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * ptr;
}Node;


struct Node * head;



int main()
{
	int i=1;
	Node * temp=NULL;
	for(i; i<=100; i++)
	{
		if(head== NULL)		//처음 일 때
		{
			temp=(Node*)malloc(sizeof(Node));
			head=temp;
		}
		else
		{
			temp->ptr=(Node*)malloc(sizeof(Node));
			temp=temp->ptr;
		}
		temp->data=i;
		temp->ptr=NULL;
	}

	i=1;
	temp=head;
	for(i; i<=100; i++)
	{
		printf("%d번째 노드의 값 : %d\n", i, temp->data);
		temp=temp->ptr;
	}	

	return 0;
}