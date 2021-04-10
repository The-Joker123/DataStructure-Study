#include <stdio.h>
#include <stdlib.h>

#define OK   1
#define ERROR   0
#define OVERFLOW   -2
typedef  int  ElemType;
typedef  int  Status;

//----- ˳����˳��洢��ʾ -----
#define LIST_INIT_SIZE 100 // �洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10 // �洢�ռ�ķ�������
typedef struct {
	ElemType* elem;	// �洢�ռ�Ļ�ַ
	int length; // ��
	int size;// �洢����
	int increment; // ����ʱ�����ӵĴ洢����
} SqList;  //˳��� 

// ����һ��˳��� 
Status InitSqlist(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.size = LIST_INIT_SIZE;
	L.increment = LISTINCREMENT;
	return OK;
}
// ��˳����Ƿ�Ϊ�ձ� 
Status ListEmpty(SqList L) {
	if (L.length == 0) return OK;
	else return ERROR;
}
//˳�����뺯��
Status ListInsert_Sq(SqList& L, int i, ElemType e) {
	L.elem[i] = e;
}


//˳���ɾ��Ԫ�غ���
Status ListDelete_Sq(SqList& L, int i, ElemType& e) {
	//���ڴ���д���룬�����㷨�����������μ��α��Ϳμ�����½�
}

//���˳�����
void OutList_Sq(SqList L)
{
	int i;
	ElemType  e;
	if (ListEmpty(L)) {
		printf("����һ���ձ�");
	}
	else
	{
		printf("˳���Ϊ��");
		for (i = 0; i < L.length; i++)
			printf("%6d", L.elem[i]);
	}
	printf("\n");
}
//������
int main()
{
	SqList L;
	int cord, i; ElemType a;
	printf("��һ��ʹ�ñ����ʼ����\n");
	do {
		printf("\n ���˵� \n");
		printf(" 1 ��ʼ��˳��� ");
		printf(" 2 ����һ��Ԫ�� ");
		printf(" 3 ɾ��һ��Ԫ�� ");
		printf(" 4 ������������ ");
		printf("\n-------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			InitSqlist(L);
			OutList_Sq(L);
			break;
		case 2:
			printf("\n������Ҫ����Ĳ���λ�ú�����Ԫ�أ��磺3 20��");
			scanf("%d%d", &i, &a);
			ListInsert_Sq(L, i, a);
			printf("\n����%dԪ��֮���", a);
			OutList_Sq(L);
			break;
		case 3:
			printf("\n������Ҫɾ��������Ԫ�ص�λ�ã��磺 3��");
			scanf("%d", &i);
			ListDelete_Sq(L, i, a);
			printf("\nɾ����%d��λ�õ�Ԫ��֮��", i);
			OutList_Sq(L);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 1;
}
