#include <stdio.h>
#include<stdlib.h>//包含了C语言的一些常用且方便的库函数
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;

#define STACK_INIT_SIZE 10//存储空间的初始分配量
#define STACKINCREMENT 5//存储空间的分配增量

typedef struct {
	ElemType* base;
	int top;
	int size;
	int increment;//扩容时，增加的存储容量
	  
	 

}SqStack;
//构造一个空栈S
Status InitStack(SqStack& S) {
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base)exit(OVERFLOW);
	S.top = 0;
	S.size = STACK_INIT_SIZE;
	S.increment = STACKINCREMENT;
	return OK;
}
//判断S是否为空栈
Status StackEmpty(SqStack S) {
	if (S.top == 0)return TRUE;
	else return FALSE;
}
//入栈函数
Status Push(SqStack& S, ElemType e) {
	ElemType* newbase;
	if (S.top >= S.size) {//若栈顶位标已经到达所分配的容器，则栈满，扩容
		newbase = (ElemType*)realloc(S.base, (S.size + S.increment) * sizeof(ElemType));
		if (NULL == newbase)return OVERFLOW;
		S.base= newbase;
		S.size += S.increment;
	}
	S.base[S.top++] = e;//将元素入栈
	return OK;
}
//出栈函数
Status Pop(SqStack& S, ElemType& e) {
	if (S.top == 0)return FALSE;
	S.top--;//将栈顶-1
	e = S.base[S.top];//让top指向的元素出栈
	return OK;
}
//输出顺序栈函数
void OutStack(SqStack S)
{
	ElemType  e;
	if (TRUE == StackEmpty(S)) {
		printf("这是一个空栈！");
	}
	else
		while (FALSE == StackEmpty(S)) {
			Pop(S, e);
			printf(" % 6d", e);
		}
	printf("\n");
}
//主函数
int main()
{
	SqStack s;
	int cord; ElemType a;
	printf("第一次使用必须初始化！\n");
	do {
		printf("\n 主菜单 \n");
		printf(" 1 初始化顺序栈 ");
		printf(" 2 插入一个元素 ");
		printf(" 3 删除栈顶元素 ");
		printf(" 4 结束程序运行 ");
		printf("\n-------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4)");
		scanf("%d",&cord);
		printf("\n");
		switch (cord)
		{
		case 1:
			InitStack(s);
			OutStack(s);
			break;
		case 2:
			printf("请输入要插入的数据元素：a=");
			scanf("%d", &a);
			Push(s, a);
			printf("%d 进栈之后的栈：", a);
			OutStack(s);
			break;
		case 3:
			Pop(s, a);
			printf("栈顶元素 %d 出栈之后的栈：", a);
			OutStack(s);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 0;
}
