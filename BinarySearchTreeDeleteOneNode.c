#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node
{
	element data;
	struct Node * llink;
	struct Node * rlink;

}Node;

Node * Head = NULL;
static int sum = 0;

Node* createNode(element data, Node * llink, Node * rlink)	// 매개변수로 이진트리에 입력 할 Data값을 받는다.
{
	Node * root = (Node*)malloc(sizeof(Node));	// 새 노드 생성
	root->data = data;
	root->llink = llink;
	root->rlink = rlink;
	return root;
}

void preOrder(Node * root)	// 전위 순회 ( D - L - R )
{	// 순회에 쓰일 temp 포인터
	while (root != NULL)
	{
		printf("[%c] -> ", root->data);
		preOrder(root->llink);
		preOrder(root->rlink);
		return;
	}
}

void inOrder(Node * root)	// 중위순회 ( L - D - R )
{
	Node * temp = root;
	while (temp != NULL)
	{
		inOrder(temp->llink);
		printf("[%c] -> ", temp->data);
		inOrder(temp->rlink);
		return;
	}
}

void postOrder(Node * root)	// 후위 순회 ( L - R - D )
{
	Node * temp = root;
	while (temp != NULL)
	{
		postOrder(temp->llink);
		postOrder(temp->rlink);
		printf("[%d] -> ", temp->data);
		return;
	}
}


void deleteNode(Node * root, int key)	// key 값을 가진 노드를 탐색 후 삭제
{
	Node * p = root;
	Node * q = NULL;
	while (p != NULL)
	{
		if (p->data == key)
			break;
		else if (key > p->data)	// 오른쪽 트리로 이동해야될 때
		{
			q = p;
			p = p->rlink;
		}
		else	// 왼쪽 트리로 이동해야 될 때
		{
			q = p;
			p = p->llink;
		}
	}
	if (p == NULL)
	{
		printf("찾고자 하는 Key값이 트리에 존재하지 않습니다!\n");
		exit(1);
	}


	if (p->llink == NULL && p->rlink == NULL)	// 삭제 할 노드의 자손이 없는 경우
	{	// q는 p의 부모 노드, p는 삭제 할 노드
		if (q->llink == p)
			q->llink = NULL;
		else
			q->rlink = NULL;
		free(p);
	}
	else if (p->llink != NULL && p->rlink != NULL)	//삭제 할 노드의 자손이 두 개 인경우
	{
		Node * temp = p;	//temp가 삭제할 노드
		Node * pP=p;
		p = p->llink;
		while (p->rlink != NULL)
		{
			pP = p;
			p = p->rlink;
		}
		if (p->llink != NULL)
		{
			pP->rlink = p->llink;
			p->llink = NULL;
		}
		else if( p->llink == NULL && temp!=pP )
		{
			pP->rlink = NULL;
		}
		else
		{
			temp->llink = NULL;
		}
		temp->data = p->data;
		free(p);
	}
	else		// 삭제 할 노드의 자손이 한 개 인경우
	{
		Node * temp = p;
		if (p->llink != NULL)	// 자손이 왼쪽 트리에 있을 때
		{
			temp = p->llink;	// temp 는 삭제할 노드 p의 자손
			if (q->llink == p)
				q->llink = temp;
			else
				q->rlink = temp;
			p->llink = NULL;
			free(p);
		}
		else if (p->rlink != NULL)
		{
			temp = p->rlink;
			if (q->llink == p)
				q->llink = temp;
			else
				q->rlink = temp;
			p->rlink = NULL;
			free(p);
		}
	}
}

int main()
{
	Node * temp = NULL;
	Node * n9 = createNode(16, NULL, NULL);
	Node * n8 = createNode(11, NULL, NULL);
	Node * n4 = createNode(2, NULL, NULL);
	Node * n7 = createNode(4, NULL, NULL);
	Node * n5 = createNode(5, n7, NULL);
	Node * n6 = createNode(14, n8, n9);
	Node * n3 = createNode(10, NULL, n6);	// D:/
	Node * n2 = createNode(3, n4, n5);	// C:/
	Node * n1 = createNode(8, n2, n3);	// 내 컴퓨터
	Head = n1;
	//printf("전위 순회!\n");
	//preOrder(Head);
	//printf("\n중위 순회!\n");
	//inOrder(Head);
	printf("\n후위 순회!\n");
	postOrder(Head);
	deleteNode(Head, 14);
	printf("\n후위 순회!\n");
	postOrder(Head);
	//printf("sum : %d\n", sum);
	//printf("\n");
	return 0;
}

// 이진 탐색 트리의 삭제 프로그램
// 이진 탐색 트리의 삭제 시, 삭제 할 노드가 두 개의 자식 노드를 갖고 있을 때의 알고리즘이 중요하다!
// 왼쪽 자식 트리 중 가장 오른쪽, 즉 가장 큰 값으로 대체하거나
// 오른쪽 자식 트리중 가장 왼쪽, 즉 가장 작은 값으로 대체해야 한다.
// 위 소스는 왼쪽 자식 트리 중 가장 큰 값으로 삭제 할 노드의 자리에 데이터를 대체하였다.
// 주의할 점은 대체 할 노드가 왼쪽 자식을 갖고 있을 때, 