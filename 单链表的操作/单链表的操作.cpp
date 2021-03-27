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

//�����ǽ���������
void CreatList_L(LinkList& head)
{
	LinkList tail, p;
	int n, i;
	p = (Lnode*)malloc(sizeof(Lnode));
	head = tail = p;
	head->next = NULL;
	printf("\n����������ĳ���:");
	scanf("%d", &n);
	printf("\n������%d����������Ԫ��", n);
	for (i = 1; i <= n; i++) {
		p = (Lnode*)malloc(sizeof(Lnode));
		scanf("%d", &p->data);
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	printf("\n������Ľ����ɹ�!");
}

//���������������
void OutputList_L(LinkList L) {
	LinkList p = L->next;
	if (p == NULL) {
		printf("��һ���ձ�\n");
		return;
	}
	printf("��������:");
	while (p) {
		printf("%4d", p->data);
		p = p->next;
	}
	printf("\n");
}


//�ڵ� i ��Ԫ��֮ǰ����һ��Ԫ��
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

// ɾ���� i ��Ԫ��
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
	printf("\n��һ��ʹ�����ȴ���һ��������\n");
	do {
		printf("\n ���˵� \n");
		printf(" 1 ����һ�������� ");
		printf(" 2 ����һ��Ԫ�� ");
		printf(" 3 ɾ��һ��Ԫ�� ");
		printf(" 4 ������������ ");
		printf("\n-------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			CreatList_L(L);
			OutputList_L(L);
			break;
		case 2:
			printf("\n������Ҫ����Ĳ���λ�ú�����Ԫ�أ��磺3 20��");
			scanf("%d%d", &i, &a);

			if (ListInsert_L(L, i, a))
			{
				printf("\n����Ԫ�سɹ�!����%dԪ��֮���", a);
				OutputList_L(L);
			}
			else printf("����Ԫ��ʧ��!\n");
			break;
		case 3:
			printf("\n������Ҫɾ��������Ԫ�ص�λ�ã��磺 3��");
			scanf("%d", &i);
			if (ListDelete_L(L, i, a))
			{
				printf("\nɾ��Ԫ�سɹ�����ɾ����Ԫ���� %d\n", a);
				printf("\nɾ����%d��λ�õ�Ԫ��֮��", i);
				OutputList_L(L);
			}
			else printf("ɾ��λ�ô���������ִ��!\n");
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 1;
}
