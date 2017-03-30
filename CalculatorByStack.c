#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NStack	//피연산자 스택
{
	double data[10];
	int top;	// 꼭대기를 가리킬 포인터
}NStack;

typedef struct OpStack	//연산자 스택
{
	char data[10];
	int top;
}OpStack;

typedef struct veriable
{
	char name;	// 변수명
	double data;	// 데이터 값(숫자)
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


	Veriable ver[2];	//변수 두개와 그 데이터를 저장 할 수 있는 구조체 배열

	char str[50];	//사용자가 처음 입력할 문장 식 String
	char * tempNum;		//입력받은 정수값만 뽑아서 저장할 변수
	char op;	 // 괄호를 만났을 때 연사자를 담을 문자형 변수
	int i = 0;	//반복문에 사용 될 정수형 변수
	int k = 0;
	int length;	//입력받은 문자열의 길이
	int numOfVer = 0;		//생성한 변수의 갯수, 최대 2
	double result = 0;	// 계산 결과

	while (1)	//문장이 종료 될 때까지 반복
	{
		result = 0;
		printf("Input >> ");
		scanf("%s", str);
		length = strlen(str);
		if (strcmp("quit", str) == 0)
			break;	//반복문 종료

		if (isAlpha(str[0]))	//첫 문자가 변수 일 때 ( 대입식)
		{
			printf("첫 문자가 알파벳임\n");
		}
		else	// 첫 문자가 숫자 일 때 (단순 계산)
		{
			printf("첫 문자가 숫자임\n");
			for (i = 0; i < length; i++)	//처음부터 끝까지 탐색
			{
				if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')	//연산자 일 때
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
						result *= result;	//제곱을 시킨다.
						numberPush(nStack, result);
						break;
					}
				}
				else if (str[i] == '(' || str[i] == ')')	//괄호를 만났을 때
				{
					switch (str[i])
					{
					case '(':
						operatorPush(opStack, '(');
						break;
					case ')':	// op stack 에서 '('가 나올때까지 pop하며 연산을 수행한다.
						while (1)
						{
						op = operaterPop(opStack);		// 연산자를 pop한다.
						if (op == '(')
							break;
						calculate(nStack, op);
						}
						break;
					}
				}
				else					// 피연산자 일때
				{
					tempNum = (char*)malloc(sizeof(char) + 10);
					k = 0;
					while (str[i + k] >= 48 && str[i + k] <= 57)
					{
						tempNum[k] = str[i + k];
						k++;
					}
					tempNum[k + 1] = '\0';
					i += k - 1;		// 증감문에서 i를 증가시키기 때문에 1를 추가로 더하지 않는다.
					double num = (double)atoi(tempNum);
					numberPush(nStack, num);
				}
			}	// for()

			while (opStack->top != -1)	//오퍼랜드 스택이 다 빌 때 까지
			{
				char ch = operaterPop(opStack);
				calculate(nStack, ch);
			}	// while()
			result = numberPop(nStack);
			printf("결과 : %lf\n", result);
		}	// else()

	}	// while()
	printf("프로그램을 종료합니다.\n");
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

int isAlpha(char data)	// 파라미터로 넘겨진 문자가 알파벳이면 1을 반환 아니면 0을 반환
{
	if (data >= 97 && data <= 122)
		return 1;
	else
		return 0;
}

void calculate(NStack * nPtr, char op)	//연산자 한개와 숫자 두개를 pop합여 계산후 다시 nStack에 Push하는 메소드
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
		printf("여기나옴\n");
		num2 = numberPop(nPtr);
		num1 = numberPop(nPtr);
		numberPush(nPtr, (num1 / num2));
		break;
	}
}

// 계산이 되어야 하는 시점
// 1. 괄호의 시작을 만난 후 끝을 만났을 때 계산해야함
// 2. 문장으 맨 끝 '\0' 일 때 계산을 함

// 계산의 방식 2가지
// 단순 숫자 연산 ( 변수가 없을 때 ) ( 10 + 20 )
// 변수가 있고 계산값을 변수에 넣을 때 ( x = 10 + 20 ) 대입식은 왼쪽 피연산자가 변수여야 한다.


// a ~ z ( 97 ~ 122 )
// 0 ~ 1 ( 48 ~ 57 )