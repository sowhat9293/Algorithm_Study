#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int time;
	struct Node * ptr;		// 다음 큐의 주소를 저장할 포인터
}Node;

Node * head;		// 머리
Node * tail;		// 꼬리

void makeQue(int num);	//큐 전체 생성
Node* dQue();	//큐 삭제
void enQue(int time);	//큐 생성
void printQue(Node * ptr);	//큐 출력
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

Node* dQue()			//큐 노드 삭제
{
	Node * temp = head;	//삭제 될 노드
	head = head->ptr;
	tail->ptr = head;
	printf("[%d] 삭제 -> ", temp->time);
	printQue(head);
	return temp;
}

void enQue(int time)	//큐 노드 생성
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
	printf("[%d] 생성 -> ", time);
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
	int robinTime = 2;		//2초씩 돌아간다.
	Node * temp = head;
	while (1)
	{
		if (head == NULL)		//모든 프로세스가 끝났을 때
		{
			printf("모든 프로세스가 종료되었으므로 라운드 로빈을 종료합니다.\n");
			printf("총 수행 시간 : %d\n", totalTime);
			break;
		}

		if (temp->time > 2 && temp->time != 0)
		{
			temp->time -= robinTime;		//수행시간을 2초 감소시킨다.
			totalTime += robinTime;
			temp = temp->ptr;
		}
		else
		{
			totalTime += temp->time;
			temp->time = 0;
			printf("수행 시간 %d에 큐 삭제 발생!", totalTime);
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
	else	//삭제할 노드가 중간에 있을 때
	{
	}
}