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

Node* createNode(element data, Node * llink, Node * rlink)	// �Ű������� ����Ʈ���� �Է� �� Data���� �޴´�.
{
	Node * root = (Node*)malloc(sizeof(Node));	// �� ��� ����
	root->data = data;
	root->llink = llink;
	root->rlink = rlink;
	return root;
}

void preOrder(Node * root)	// ���� ��ȸ ( D - L - R )
{	// ��ȸ�� ���� temp ������
	while (root != NULL)
	{
		printf("[%c] -> ", root->data);
		preOrder(root->llink);
		preOrder(root->rlink);
		return;
	}
}

void inOrder(Node * root)	// ������ȸ ( L - D - R )
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

void postOrder(Node * root)	// ���� ��ȸ ( L - R - D )
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


void deleteNode(Node * root, int key)	// key ���� ���� ��带 Ž�� �� ����
{
	Node * p = root;
	Node * q = NULL;
	while (p != NULL)
	{
		if (p->data == key)
			break;
		else if (key > p->data)	// ������ Ʈ���� �̵��ؾߵ� ��
		{
			q = p;
			p = p->rlink;
		}
		else	// ���� Ʈ���� �̵��ؾ� �� ��
		{
			q = p;
			p = p->llink;
		}
	}
	if (p == NULL)
	{
		printf("ã���� �ϴ� Key���� Ʈ���� �������� �ʽ��ϴ�!\n");
		exit(1);
	}


	if (p->llink == NULL && p->rlink == NULL)	// ���� �� ����� �ڼ��� ���� ���
	{	// q�� p�� �θ� ���, p�� ���� �� ���
		if (q->llink == p)
			q->llink = NULL;
		else
			q->rlink = NULL;
		free(p);
	}
	else if (p->llink != NULL && p->rlink != NULL)	//���� �� ����� �ڼ��� �� �� �ΰ��
	{
		Node * temp = p;	//temp�� ������ ���
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
	else		// ���� �� ����� �ڼ��� �� �� �ΰ��
	{
		Node * temp = p;
		if (p->llink != NULL)	// �ڼ��� ���� Ʈ���� ���� ��
		{
			temp = p->llink;	// temp �� ������ ��� p�� �ڼ�
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
	Node * n1 = createNode(8, n2, n3);	// �� ��ǻ��
	Head = n1;
	//printf("���� ��ȸ!\n");
	//preOrder(Head);
	//printf("\n���� ��ȸ!\n");
	//inOrder(Head);
	printf("\n���� ��ȸ!\n");
	postOrder(Head);
	deleteNode(Head, 14);
	printf("\n���� ��ȸ!\n");
	postOrder(Head);
	//printf("sum : %d\n", sum);
	//printf("\n");
	return 0;
}

// ���� Ž�� Ʈ���� ���� ���α׷�
// ���� Ž�� Ʈ���� ���� ��, ���� �� ��尡 �� ���� �ڽ� ��带 ���� ���� ���� �˰����� �߿��ϴ�!
// ���� �ڽ� Ʈ�� �� ���� ������, �� ���� ū ������ ��ü�ϰų�
// ������ �ڽ� Ʈ���� ���� ����, �� ���� ���� ������ ��ü�ؾ� �Ѵ�.
// �� �ҽ��� ���� �ڽ� Ʈ�� �� ���� ū ������ ���� �� ����� �ڸ��� �����͸� ��ü�Ͽ���.
// ������ ���� ��ü �� ��尡 ���� �ڽ��� ���� ���� ��, 