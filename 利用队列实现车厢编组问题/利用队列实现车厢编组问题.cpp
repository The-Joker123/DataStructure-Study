#include <stdio.h>
#include <stdlib.h>
#define OK   1
#define ERROR   0
#define OVERFLOW  -2
#define  TRUE  1
#define FALSE  0
typedef  char   ElemType;
typedef int  Status;
//----- ���е�˳��洢��ʾ -----
#define  MAXQSIZE  30 // �洢�ռ�ĳ�ʼ������
typedef struct {
	ElemType* base;
	int front;
	int rear;
	int maxSize;
} SqQueue;
// ����һ���ն��� Q
Status InitQueue(SqQueue& Q) {
	Q.base = (ElemType*)malloc(MAXQSIZE * sizeof(ElemType));
	if (!Q.base)	exit(OVERFLOW);
	Q.front = Q.rear = 0;
	Q.maxSize = MAXQSIZE;
	return OK;
}
//�ж����Ƿ�Ϊ��
Status QueueEmpty(SqQueue Q) {
	if (Q.rear == Q.front) return   TRUE;
	else return   FALSE;
}
//��Ӻ���
Status EnQueue(SqQueue& Q, ElemType e) {
	if ((Q.rear + 1) % Q.maxSize == Q.front)return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.maxSize;
	return OK;
}
//���Ӻ���
Status DeQueue(SqQueue& Q, ElemType& e) {
	if (Q.front == Q.rear)return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.maxSize;
	return OK;
}
//���ѭ�����к���
void OutQueue(SqQueue Q)
{
	ElemType e;
	if (QueueEmpty(Q)) {
		printf("����һ���ն��У�");
	}
	else {
		while (QueueEmpty(Q) == FALSE) {
			DeQueue(Q, e);
			printf(" % 6c", e);
		}
		printf("\n");
	}
}
void Arrange(SqQueue A, SqQueue& B, SqQueue& C) {
	char  e;
	InitQueue(B);
	InitQueue(C);
	while (QueueEmpty(A)== FALSE) {
		DeQueue(A, e);
		if (e=='S' )
		{
			EnQueue(C, e);//����
		}
		else
		{
			EnQueue(B, e);//Ӳ��
		}
	}
	
}
//������
void main()
{
	SqQueue A, B, C;
	ElemType e;
	InitQueue(A);
	printf("����������S��Ӳ��H��һ����ϳ��飺");
	for (scanf("%c", &e); e != '\n';) {
		EnQueue(A, e);
		scanf("%c", &e);
	}
	Arrange(A, B, C);
	printf("Ӳ�����飺");
	OutQueue(B);
	printf("���Գ��飺");
	OutQueue(C);
}
