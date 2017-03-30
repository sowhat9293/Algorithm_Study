#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int time;
	struct Node * ptr;		// ���� ť�� �ּҸ� ������ ������
}Node;

Node * head;		// �Ӹ�
Node * tail;		// ����

void makeQue(int num);	//ť ��ü ����
Node* dQue();	//ť ����
void enQue(int time);	//ť ����
void printQue(Node * ptr);	//ť ���
void roundRobin();


int main()
{
	int i;
	head = NULL;
	tail = NULL;
	Node * temp = NULL;
	enQue(12);
	enQue(10);
	enQue(5);
	enQue(7);

	roundRobin();


	return 0;
}

void makeQue(int num)
{
	Node * temp = NULL;
	int i;
	for (i = 1; i <= num; i++)
	{
		if (i == 1)
		{
			head = (Node*)malloc(sizeof(Node));
			head->time = i;
			head->ptr = NULL;
			temp = head;
		}
		else
		{
			temp->ptr = (Node*)malloc(sizeof(Node));
			temp = temp->ptr;
			temp->time = i;
			temp->ptr = NULL;
		}
	}
	tail = temp;
	tail->ptr = head;
}

Node* dQue()			//ť ��� ����
{
	Node * temp = head;	//���� �� ���
	head = head->ptr;
	tail->ptr = head;
	printf("[%d] ���� -> ", temp->time);
	printQue(head);
	return temp;
}

void enQue(int time)	//ť ��� ����
{
	Node * temp = (Node*)malloc(sizeof(Node));
	temp->time = time;
	temp->ptr = head;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->ptr = temp;
		tail = temp;
	}
	printf("[%d] ���� -> ", time);
	printQue(head);
}

void printQue(Node * ptr)
{
	while (1)
	{
		if (ptr == tail)
		{
			printf("[ %d ]\n", ptr->time);
			break;
		}
		printf("[ %d ]  ", ptr->time);
		ptr = ptr->ptr;
	}
}

void roundRobin()
{
	int totalTime = 0;
	int robinTime = 2;		//2�ʾ� ���ư���.
	Node * temp = head;
	while (1)
	{
		if (head == NULL)		//��� ���μ����� ������ ��
		{
			printf("��� ���μ����� ����Ǿ����Ƿ� ���� �κ��� �����մϴ�.\n");
			printf("�� ���� �ð� : %d\n", totalTime);
			break;
		}

		if (temp->time > 2 && temp->time != 0)
		{
			temp->time -= robinTime;		//����ð��� 2�� ���ҽ�Ų��.
			totalTime += robinTime;
			temp = temp->ptr;
		}
		else
		{
			totalTime += temp->time;
			temp->time = 0;
			printf("���� �ð� %d�� ť ���� �߻�!", totalTime);
		}
	}
}


void deleteQue(Node * temp)
{
	if (head == temp)
	{
		
	}
	else if (tail == temp)
	{
	}
	else	//������ ��尡 �߰��� ���� ��
	{
	}
}