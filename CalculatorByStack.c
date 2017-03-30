#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NStack	//�ǿ����� ����
{
	double data[10];
	int top;	// ����⸦ ����ų ������
}NStack;

typedef struct OpStack	//������ ����
{
	char data[10];
	int top;
}OpStack;

typedef struct veriable
{
	char name;	// ������
	double data;	// ������ ��(����)
}Veriable;

int isAlpha(char data);
void numberPush(NStack * ptr, double num);
void operatorPush(OpStack * ptr, char op);
double numberPop(NStack * ptr);
char operaterPop(OpStack * ptr);
void calculate(NStack * nPtr, char op);



int main()
{
	NStack * nStack = (NStack*)malloc(sizeof(NStack));
	nStack->top = -1;
	OpStack * opStack = (OpStack*)malloc(sizeof(OpStack));
	opStack->top = -1;


	Veriable ver[2];	//���� �ΰ��� �� �����͸� ���� �� �� �ִ� ����ü �迭

	char str[50];	//����ڰ� ó�� �Է��� ���� �� String
	char * tempNum;		//�Է¹��� �������� �̾Ƽ� ������ ����
	char op;	 // ��ȣ�� ������ �� �����ڸ� ���� ������ ����
	int i = 0;	//�ݺ����� ��� �� ������ ����
	int k = 0;
	int length;	//�Է¹��� ���ڿ��� ����
	int numOfVer = 0;		//������ ������ ����, �ִ� 2
	double result = 0;	// ��� ���

	while (1)	//������ ���� �� ������ �ݺ�
	{
		result = 0;
		printf("Input >> ");
		scanf("%s", str);
		length = strlen(str);
		if (strcmp("quit", str) == 0)
			break;	//�ݺ��� ����

		if (isAlpha(str[0]))	//ù ���ڰ� ���� �� �� ( ���Խ�)
		{
			printf("ù ���ڰ� ���ĺ���\n");
		}
		else	// ù ���ڰ� ���� �� �� (�ܼ� ���)
		{
			printf("ù ���ڰ� ������\n");
			for (i = 0; i < length; i++)	//ó������ ������ Ž��
			{
				if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')	//������ �� ��
				{
					switch (str[i])
					{
					case '+':
						operatorPush(opStack, '+');
						break;
					case '-':
						operatorPush(opStack, '-');
						break;
					case '*':
						operatorPush(opStack, '*');
						break;
					case '/':
						operatorPush(opStack, '/');
						break;
					case '^':
						result = numberPop(nStack);
						result *= result;	//������ ��Ų��.
						numberPush(nStack, result);
						break;
					}
				}
				else if (str[i] == '(' || str[i] == ')')	//��ȣ�� ������ ��
				{
					switch (str[i])
					{
					case '(':
						operatorPush(opStack, '(');
						break;
					case ')':	// op stack ���� '('�� ���ö����� pop�ϸ� ������ �����Ѵ�.
						while (1)
						{
						op = operaterPop(opStack);		// �����ڸ� pop�Ѵ�.
						if (op == '(')
							break;
						calculate(nStack, op);
						}
						break;
					}
				}
				else					// �ǿ����� �϶�
				{
					tempNum = (char*)malloc(sizeof(char) + 10);
					k = 0;
					while (str[i + k] >= 48 && str[i + k] <= 57)
					{
						tempNum[k] = str[i + k];
						k++;
					}
					tempNum[k + 1] = '\0';
					i += k - 1;		// ���������� i�� ������Ű�� ������ 1�� �߰��� ������ �ʴ´�.
					double num = (double)atoi(tempNum);
					numberPush(nStack, num);
				}
			}	// for()

			while (opStack->top != -1)	//���۷��� ������ �� �� �� ����
			{
				char ch = operaterPop(opStack);
				calculate(nStack, ch);
			}	// while()
			result = numberPop(nStack);
			printf("��� : %lf\n", result);
		}	// else()

	}	// while()
	printf("���α׷��� �����մϴ�.\n");
	return 0;
}


void numberPush(NStack * ptr, double num)
{
	ptr->data[++(ptr->top)] = num;
}

void operatorPush(OpStack * ptr, char op)
{
	ptr->data[++(ptr->top)] = op;
}

double numberPop(NStack * ptr)
{
	return ptr->data[(ptr->top)--];
}

char operaterPop(OpStack * ptr)
{
	return ptr->data[(ptr->top)--];
}

int isAlpha(char data)	// �Ķ���ͷ� �Ѱ��� ���ڰ� ���ĺ��̸� 1�� ��ȯ �ƴϸ� 0�� ��ȯ
{
	if (data >= 97 && data <= 122)
		return 1;
	else
		return 0;
}

void calculate(NStack * nPtr, char op)	//������ �Ѱ��� ���� �ΰ��� pop�տ� ����� �ٽ� nStack�� Push�ϴ� �޼ҵ�
{
	double num1;
	double num2;
	switch (op)
	{
	case '+':
		num2 = numberPop(nPtr);
		num1 = numberPop(nPtr);
		numberPush(nPtr, (num1 + num2));
		break;
	case '-':
		num2 = numberPop(nPtr);
		num1 = numberPop(nPtr);
		numberPush(nPtr, (num1 - num2));
		break;
	case '*':
		num2 = numberPop(nPtr);
		num1 = numberPop(nPtr);
		numberPush(nPtr, (num1 * num2));
		break;
	case '/':
		printf("���⳪��\n");
		num2 = numberPop(nPtr);
		num1 = numberPop(nPtr);
		numberPush(nPtr, (num1 / num2));
		break;
	}
}

// ����� �Ǿ�� �ϴ� ����
// 1. ��ȣ�� ������ ���� �� ���� ������ �� ����ؾ���
// 2. ������ �� �� '\0' �� �� ����� ��

// ����� ��� 2����
// �ܼ� ���� ���� ( ������ ���� �� ) ( 10 + 20 )
// ������ �ְ� ��갪�� ������ ���� �� ( x = 10 + 20 ) ���Խ��� ���� �ǿ����ڰ� �������� �Ѵ�.


// a ~ z ( 97 ~ 122 )
// 0 ~ 1 ( 48 ~ 57 )