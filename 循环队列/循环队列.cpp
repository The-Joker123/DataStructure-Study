#include <stdio.h>
#include <stdlib.h>
#define OK   1
#define ERROR   0
#define OVERFLOW  -2
#define TRUE  1
#define  FALSE  0
typedef  int  ElemType;
typedef int  Status;
//----- 队列的顺序存储表示 -----
#define  MAXQSIZE  30 // 存储空间的初始分配量
typedef struct {
	ElemType* base;//存储空间的基址
	int front;//队头位标
	int rear;//队尾位标，指示队尾的下一个位置
	int maxSize;//存储容量
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
		while (!QueueEmpty(Q)) {
			DeQueue(Q, e);
			printf("% 6d", e);
		}
		printf("\n");
	}
}
//主函数
int main()
{
	SqQueue q;
	int cord;
	ElemType a;
	printf("第一次使用必须初始化！\n");
	do {
		printf("\n 主菜单 \n");
		printf(" 1 初始化循环队列 ");
		printf(" 2 进队一个元素 ");
		printf(" 3 出队一个元素 ");
		printf(" 4 结束程序运行 ");
		printf("\n------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			InitQueue(q); //调用初始化算法;
			OutQueue(q);
			break;
		case 2:
			printf("请输入要插入的数据元素：a=");
			scanf("%d", &a);
			EnQueue(q, a); //调用进队算法;
			printf("%d 进队之后的队列：", a);
			OutQueue(q);
			break;
		case 3:
			DeQueue(q, a); //调用出队算法;
			printf("队头元素 %d 出队之后的队列：", a);
			OutQueue(q);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 0;
}
