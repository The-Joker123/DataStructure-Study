#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE  1
#define FALSE  0
#define OVERFLOW -2
typedef char ElemType;
typedef int Status;
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 5
typedef struct 
{
	ElemType* base;
	int top;
	int size;
	int increment; // 扩容时，增加的存储容量
} SqStack;
// 构造一个空栈 S
Status InitStack(SqStack& S)
{
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = 0;
	S.size = STACK_INIT_SIZE;
	S.increment = STACKINCREMENT;
	return OK;
}
// 判栈 S 是否为空栈
Status StackEmpty(SqStack S)
{
	if (S.top == 0) return   TRUE;
	else return   FALSE;
}
//入栈函数
Status Push(SqStack& S, ElemType e) {
	ElemType* newbase;
	if (S.top >= S.size) 
	{
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
Status GetTop(SqStack& S, ElemType& e)
{
	if (S.top == 0) return ERROR;
	e = S.base[S.top];
	return OK;
}
Status Matching(char* exp, int n)
{
	int i = 0;
	ElemType e;
	SqStack S;
	InitStack(S);
	while (i < n)
	{
		switch (exp[i])
		{
		case '(':
		case '[':Push(S, exp[i]); i++; break;
		case ')':
		case ']':
				if (TRUE == StackEmpty(S))
					return ERROR;
				else
				{
					GetTop(S, e);
					if ((exp[i] == ')' && e == '(') || (exp[i] == ']' && e == '['))
					{
						Pop(S, e); i++;
					}
					else return ERROR;
				}
				break;
		
		}
	}
	if (TRUE == StackEmpty(S)) {
		return OK;
	}
	else
	{
		return ERROR;
	}
	
}
int conversion()
{
	//	SqStack S;
	char e[] = "(1+2) ";


	if (Matching(e, 15))
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
int main()
{
	printf("%d",conversion());
	
	return 0;
}