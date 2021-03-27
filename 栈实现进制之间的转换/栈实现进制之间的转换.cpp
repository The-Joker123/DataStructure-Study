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
	int increment; // 扩容时，增加的存储容量
} SqStack;
// 构造一个空栈 S
Status InitStack(SqStack& S) {
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = 0;
	S.size = STACK_INIT_SIZE;
	S.increment = STACKINCREMENT;
	return OK;
}
// 判栈 S 是否为空栈
Status StackEmpty(SqStack S) {
	if (S.top == 0) return   TRUE;
	else return   FALSE;
}
//入栈函数
Status Push(SqStack& S, ElemType e) {
	ElemType* newbase;
	if (S.top >= S.size) {
		newbase = (ElemType*)realloc(S.base, (S.size + S.increment) * sizeof(ElemType));
		if (NULL == newbase) return OVERFLOW;
		S.base = newbase;
		S.size += S.increment;
	}
	S.base[S.top++] = e;//将余数压入栈
	return OK;
}
//出栈函数
Status Pop(SqStack& S, ElemType& e) {
	if (S.top == 0) return ERROR;
	S.top--;
	e = S.base[S.top];
	return OK;
}
//十进制转八进制函数
void conversion()
{
	SqStack S;
	int  n, d;
	ElemType e;
	printf("输入要转换的数：");
	scanf("%d", &n);
	printf("输入要转换的进制：");
	scanf("%d", &d);
	InitStack(S);
	while (n != 0) {
		Push(S, n % d);//余数压住栈
		n /= d;
	}
	while (FALSE == StackEmpty(S)) {
		Pop(S, e);//余数出栈
		printf("%d", e);
	}
}
int main()
{
	conversion();
	return 0;
}
//测试