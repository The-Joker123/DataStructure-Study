#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE  1
#define FALSE  0
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 5
typedef struct {
	ElemType* base;
	int top;
	int size;
	int increment; // ����ʱ�����ӵĴ洢����
} SqStack;
// ����һ����ջ S
Status InitStack(SqStack& S) {
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = 0;
	S.size = STACK_INIT_SIZE;
	S.increment = STACKINCREMENT;
	return OK;
}
// ��ջ S �Ƿ�Ϊ��ջ
Status StackEmpty(SqStack S) {
	if (S.top == 0) return   TRUE;
	else return   FALSE;
}
//��ջ����
Status Push(SqStack& S, ElemType e) {
	ElemType* newbase;
	if (S.top >= S.size) {
		newbase = (ElemType*)realloc(S.base, (S.size + S.increment) * sizeof(ElemType));
		if (NULL == newbase) return OVERFLOW;
		S.base = newbase;
		S.size += S.increment;
	}
	S.base[S.top++] = e;//������ѹ��ջ
	return OK;
}
//��ջ����
Status Pop(SqStack& S, ElemType& e) {
	if (S.top == 0) return ERROR;
	S.top--;
	e = S.base[S.top];
	return OK;
}
//ʮ����ת�˽��ƺ���
void conversion()
{
	SqStack S;
	int  n, d;
	ElemType e;
	printf("����Ҫת��������");
	scanf("%d", &n);
	printf("����Ҫת���Ľ��ƣ�");
	scanf("%d", &d);
	InitStack(S);
	while (n != 0) {
		Push(S, n % d);//����ѹסջ
		n /= d;
	}
	while (FALSE == StackEmpty(S)) {
		Pop(S, e);//������ջ
		printf("%d", e);
	}
}
int main()
{
	conversion();
	return 0;
}