#include <stdio.h>
#include <stdlib.h>
#define OK   1
#define ERROR   0
#define OVERFLOW  -2
#define TRUE  1
#define  FALSE  0
typedef  int  ElemType;
typedef int  Status;
//----- ���е�˳��洢��ʾ -----
#define  MAXQSIZE  30 // �洢�ռ�ĳ�ʼ������
typedef struct {
	ElemType* base;//�洢�ռ�Ļ�ַ
	int front;//��ͷλ��
	int rear;//��βλ�ָ꣬ʾ��β����һ��λ��
	int maxSize;//�洢����
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
		while (!QueueEmpty(Q)) {
			DeQueue(Q, e);
			printf("% 6d", e);
		}
		printf("\n");
	}
}
//������
int main()
{
	SqQueue q;
	int cord;
	ElemType a;
	printf("��һ��ʹ�ñ����ʼ����\n");
	do {
		printf("\n ���˵� \n");
		printf(" 1 ��ʼ��ѭ������ ");
		printf(" 2 ����һ��Ԫ�� ");
		printf(" 3 ����һ��Ԫ�� ");
		printf(" 4 ������������ ");
		printf("\n------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			InitQueue(q); //���ó�ʼ���㷨;
			OutQueue(q);
			break;
		case 2:
			printf("������Ҫ���������Ԫ�أ�a=");
			scanf("%d", &a);
			EnQueue(q, a); //���ý����㷨;
			printf("%d ����֮��Ķ��У�", a);
			OutQueue(q);
			break;
		case 3:
			DeQueue(q, a); //���ó����㷨;
			printf("��ͷԪ�� %d ����֮��Ķ��У�", a);
			OutQueue(q);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 0;
}
