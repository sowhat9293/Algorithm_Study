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
void dQue();	//큐 삭제
void enQue(int time);	//큐 생성
void printQue(Node * ptr);	//큐 출력
void roundRobin();
Node* makeNode();	//노드를 만드는 메소드
Node* mDelQue(Node * node);	//노드를 삭제하는 메소드
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

void dQue()			//큐 노드 삭제
{
	Node * temp = head;	//삭제 될 노드
	head = head->ptr;
	tail->ptr = head;
	printf("[%d] 삭제 -> ", temp->time);
	printQue(head);
	free(temp);	//동적 할당 해제
}

void enQue(int time)	//큐 노드 생성
{
	if (head == NULL)	// 빈 큐 일 때
	{
		head = makeNode();
		head->time = time;
		head->ptr = head;
		tail = head;
	}
	else	// 비어있는 큐가 아닐 때
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
	int robinTime = 2;		//2초씩 돌아간다.
	Node * proc = head;		// proc는 cpu를 갖고있는 프로세스 노드
	int i;	//반복문에 쓰일 변수

	while (head != NULL)	//모든 노드가 사라질때까지 무한 반복
	{
		printf("############CPU Time이 넘어갔습니다.###############\n");
		for (i = 0; i < robinTime; i++)
		{
			if (hasNextNode(proc) == 1)	 // 감소할 cpu time이 남아 있을 때
			{
				proc->time--;
				totalTime++;
				printf("Time : %d\t Running Proc!\n", totalTime);
			}
			else if (hasNextNode(proc) == 0)		//감소할 cpu time이 없을 때
			{
				proc = mDelQue(proc);
				if (proc == NULL)
				{
					printf("모든 프로그램이 종료되었습니다.\n");
					printf("총 수행시간 : %d초\n", totalTime);
					return;
				}
				printf("WACTH!! Time : %d\t Proc Out!\n", totalTime);
				break;	//for문을 빠져나간다.
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
	else	//삭제할 노드가 중간에 있을 때
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
	else if (node == head)	//지우려는 노드가 head일때
	{
		temp = head;
		head = head->ptr;
		temp->ptr = NULL;
		tail = head;
		free(temp);
		if (head == NULL)
		{
			printf("head가 널입니다.\n");
			return NULL;
		}
		return tail;	// 반환되는 tail==NULL 이면 모든 노드가 삭제된 것 이다.
	}
	else if (node == tail)	//지우려는 노드가 tail일 때
	{
		Node * befNode = head;	// tail의 뒤에있는 Node
		temp = tail;
		while (befNode->ptr != tail)
			befNode = befNode->ptr;
		befNode->ptr = head;
		tail = befNode;
		temp->ptr = NULL;
		free(temp);
		return tail;
	}
	else	// 지우려는 노드가 중간에 있을 때
	{
		temp = head;	//순회할 노드
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

//원형 큐를 이용한 라운드로빈 CPU 스케쥴링 프로그램 구현