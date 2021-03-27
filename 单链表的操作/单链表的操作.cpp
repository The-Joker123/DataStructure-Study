#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;
typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode, * LinkList;

//以下是建立单链表
void CreatList_L(LinkList& head)
{
	LinkList tail, p;
	int n, i;
	p = (Lnode*)malloc(sizeof(Lnode));
	head = tail = p;
	head->next = NULL;
	printf("\n请输入链表的长度:");
	scanf("%d", &n);
	printf("\n请输入%d个整型数据元素", n);
	for (i = 1; i <= n; i++) {
		p = (Lnode*)malloc(sizeof(Lnode));
		scanf("%d", &p->data);
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	printf("\n单链表的建立成功!");
}

//以下是输出单链表
void OutputList_L(LinkList L) {
	LinkList p = L->next;
	if (p == NULL) {
		printf("是一个空表！\n");
		return;
	}
	printf("单链表是:");
	while (p) {
		printf("%4d", p->data);
		p = p->next;
	}
	printf("\n");
}


//在第 i 个元素之前插入一个元素
Status ListInsert_L(LinkList L, int i, ElemType e) {
	LinkList p, s;
	p = L;
	int j = 1;
	while (p&& j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		return  ERROR;
	}
	s = (LinkList)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

// 删除第 i 个元素
Status ListDelete_L(LinkList L, int i, ElemType& e) {
	LinkList p, q;
	p = L;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		return  ERROR;
	}
	
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);

	return OK;
}


int main()
{
	LinkList L;
	int cord, i; ElemType a;
	printf("\n第一次使用请先创建一个单链表！\n");
	do {
		printf("\n 主菜单 \n");
		printf(" 1 创建一个单链表 ");
		printf(" 2 插入一个元素 ");
		printf(" 3 删除一个元素 ");
		printf(" 4 结束程序运行 ");
		printf("\n-------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			CreatList_L(L);
			OutputList_L(L);
			break;
		case 2:
			printf("\n请输入要插入的插入位置和数据元素（如：3 20）");
			scanf("%d%d", &i, &a);

			if (ListInsert_L(L, i, a))
			{
				printf("\n插入元素成功!插入%d元素之后的", a);
				OutputList_L(L);
			}
			else printf("插入元素失败!\n");
			break;
		case 3:
			printf("\n请输入要删除的数据元素的位置（如： 3）");
			scanf("%d", &i);
			if (ListDelete_L(L, i, a))
			{
				printf("\n删除元素成功！被删除的元素是 %d\n", a);
				printf("\n删除第%d个位置的元素之后", i);
				OutputList_L(L);
			}
			else printf("删除位置错误，请重新执行!\n");
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 1;
}
