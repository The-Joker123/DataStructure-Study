#include <stdio.h>
#include<stdlib.h>//������C���Ե�һЩ�����ҷ���Ŀ⺯��
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;

#define STACK_INIT_SIZE 10//�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 5//�洢�ռ�ķ�������

typedef struct {
	ElemType* base;
	int top;
	int size;
	int increment;//����ʱ�����ӵĴ洢����
	
}SqStack;
//����һ����ջS
Status InitStack(SqStack& S) {
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base)exit(OVERFLOW);
	S.top = 0;
	S.size = STACK_INIT_SIZE;
	S.increment = STACKINCREMENT;
	return OK;
}
//�ж�S�Ƿ�Ϊ��ջ
Status StackEmpty(SqStack S) {
	if (S.top == 0)return TRUE;
	else return FALSE;
}
//��ջ����
Status Push(SqStack& S, ElemType e) {
	ElemType* newbase;
	if (S.top >= S.size) {//��ջ��λ���Ѿ��������������������ջ��������
		newbase = (ElemType*)realloc(S.base, (S.size + S.increment) * sizeof(ElemType));
		if (NULL == newbase)return OVERFLOW;
		S.base= newbase;
		S.size += S.increment;
	}
	S.base[S.top++] = e;//��Ԫ����ջ
	return OK;
}
//��ջ����
Status Pop(SqStack& S, ElemType& e) {
	if (S.top == 0)return FALSE;
	S.top--;//��ջ��-1
	e = S.base[S.top];//��topָ���Ԫ�س�ջ
	return OK;
}
//���˳��ջ����
void OutStack(SqStack S)
{
	ElemType  e;
	if (TRUE == StackEmpty(S)) {
		printf("����һ����ջ��");
	}
	else
		while (FALSE == StackEmpty(S)) {
			Pop(S, e);
			printf(" % 6d", e);
		}
	printf("\n");
}
//������
int main()
{
	SqStack s;
	int cord; ElemType a;
	printf("��һ��ʹ�ñ����ʼ����\n");
	do {
		printf("\n ���˵� \n");
		printf(" 1 ��ʼ��˳��ջ ");
		printf(" 2 ����һ��Ԫ�� ");
		printf(" 3 ɾ��ջ��Ԫ�� ");
		printf(" 4 ������������ ");
		printf("\n-------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4)");
		scanf("%d",&cord);
		printf("\n");
		switch (cord)
		{
		case 1:
			InitStack(s);
			OutStack(s);
			break;
		case 2:
			printf("������Ҫ���������Ԫ�أ�a=");
			scanf("%d", &a);
			Push(s, a);
			printf("%d ��ջ֮���ջ��", a);
			OutStack(s);
			break;
		case 3:
			Pop(s, a);
			printf("ջ��Ԫ�� %d ��ջ֮���ջ��", a);
			OutStack(s);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 0;
}
