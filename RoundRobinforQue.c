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
void dQue();	//ť ����
void enQue(int time);	//ť ����
void printQue(Node * ptr);	//ť ���
void roundRobin();
Node* makeNode();	//��带 ����� �޼ҵ�
Node* mDelQue(Node * node);	//��带 �����ϴ� �޼ҵ�
int hasNextNode(Node* node);


int main()
{
	int i;
	head = NULL;
	tail = NULL;
	Node * temp = NULL;
	enQue(100);
	enQue(99);
	enQue(99);
	enQue(7);
	enQue(32);
	enQue(50);
	enQue(53);
	enQue(71);
	enQue(17);
	enQue(56);
	enQue(98);
	enQue(66);

	//printf("head : %d, head->ptr : %d\n", head->time, head->ptr->time);

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

void dQue()			//ť ��� ����
{
	Node * temp = head;	//���� �� ���
	head = head->ptr;
	tail->ptr = head;
	printf("[%d] ���� -> ", temp->time);
	printQue(head);
	free(temp);	//���� �Ҵ� ����
}

void enQue(int time)	//ť ��� ����
{
	if (head == NULL)	// �� ť �� ��
	{
		head = makeNode();
		head->time = time;
		head->ptr = head;
		tail = head;
	}
	else	// ����ִ� ť�� �ƴ� ��
	{
		tail->ptr = makeNode();
		tail = tail->ptr;
		tail->time = time;
		tail->ptr = head;
	}
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
	Node * proc = head;		// proc�� cpu�� �����ִ� ���μ��� ���
	int i;	//�ݺ����� ���� ����

	while (head != NULL)	//��� ��尡 ����������� ���� �ݺ�
	{
		printf("############CPU Time�� �Ѿ���ϴ�.###############\n");
		for (i = 0; i < robinTime; i++)
		{
			if (hasNextNode(proc) == 1)	 // ������ cpu time�� ���� ���� ��
			{
				proc->time--;
				totalTime++;
				printf("Time : %d\t Running Proc!\n", totalTime);
			}
			else if (hasNextNode(proc) == 0)		//������ cpu time�� ���� ��
			{
				proc = mDelQue(proc);
				if (proc == NULL)
				{
					printf("��� ���α׷��� ����Ǿ����ϴ�.\n");
					printf("�� ����ð� : %d��\n", totalTime);
					return;
				}
				printf("WACTH!! Time : %d\t Proc Out!\n", totalTime);
				break;	//for���� ����������.
			}
		}
		proc = proc->ptr;

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

Node* makeNode()
{
	return (Node*)malloc(sizeof(Node));
}

Node* mDelQue(Node * node)
{
	Node * temp = NULL;
	if (head == tail && head == node)
	{
		temp = node;
		head = NULL;
		tail = NULL;
		free(temp);
		return NULL;
	}
	else if (node == head)	//������� ��尡 head�϶�
	{
		temp = head;
		head = head->ptr;
		temp->ptr = NULL;
		tail = head;
		free(temp);
		if (head == NULL)
		{
			printf("head�� ���Դϴ�.\n");
			return NULL;
		}
		return tail;	// ��ȯ�Ǵ� tail==NULL �̸� ��� ��尡 ������ �� �̴�.
	}
	else if (node == tail)	//������� ��尡 tail�� ��
	{
		Node * befNode = head;	// tail�� �ڿ��ִ� Node
		temp = tail;
		while (befNode->ptr != tail)
			befNode = befNode->ptr;
		befNode->ptr = head;
		tail = befNode;
		temp->ptr = NULL;
		free(temp);
		return tail;
	}
	else	// ������� ��尡 �߰��� ���� ��
	{
		temp = head;	//��ȸ�� ���
		while (temp->ptr != node)
			temp = temp->ptr;

		temp->ptr = node->ptr;
		node->ptr = NULL;
		free(node);
		return temp;
	}
}

int hasNextNode(Node* node)
{
	if (node->time >= 1)
		return 1;
	else
		return 0;
}

//���� ť�� �̿��� ����κ� CPU �����층 ���α׷� ����