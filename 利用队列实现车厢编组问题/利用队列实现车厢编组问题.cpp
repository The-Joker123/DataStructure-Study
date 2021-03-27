#include <stdio.h>
#include <stdlib.h>
#define OK   1
#define ERROR   0
#define OVERFLOW  -2
#define  TRUE  1
#define FALSE  0
typedef  char   ElemType;
typedef int  Status;
//----- 队列的顺序存储表示 -----
#define  MAXQSIZE  30 // 存储空间的初始分配量
typedef struct {
	ElemType* base;
	int front;
	int rear;
	int maxSize;
} SqQueue;
// 构造一个空队列 Q
Status InitQueue(SqQueue& Q) {
	Q.base = (ElemType*)malloc(MAXQSIZE * sizeof(ElemType));
	if (!Q.base)	exit(OVERFLOW);
	Q.front = Q.rear = 0;
	Q.maxSize = MAXQSIZE;
	return OK;
}
//判队列是否为空
Status QueueEmpty(SqQueue Q) {
	if (Q.rear == Q.front) return   TRUE;
	else return   FALSE;
}
//入队函数
Status EnQueue(SqQueue& Q, ElemType e) {
	if ((Q.rear + 1) % Q.maxSize == Q.front)return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.maxSize;
	return OK;
}
//出队函数
Status DeQueue(SqQueue& Q, ElemType& e) {
	if (Q.front == Q.rear)return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.maxSize;
	return OK;
}
//输出循环队列函数
void OutQueue(SqQueue Q)
{
	ElemType e;
	if (QueueEmpty(Q)) {
		printf("这是一个空队列！");
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
			EnQueue(C, e);//软座
		}
		else
		{
			EnQueue(B, e);//硬座
		}
	}
	
}
//主函数
void main()
{
	SqQueue A, B, C;
	ElemType e;
	InitQueue(A);
	printf("请输入软卧S和硬座H的一个组合车组：");
	for (scanf("%c", &e); e != '\n';) {
		EnQueue(A, e);
		scanf("%c", &e);
	}
	Arrange(A, B, C);
	printf("硬座车组：");
	OutQueue(B);
	printf("软卧车组：");
	OutQueue(C);
}
