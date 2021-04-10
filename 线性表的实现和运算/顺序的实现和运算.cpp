#include <stdio.h>
#include <stdlib.h>

#define OK   1
#define ERROR   0
#define OVERFLOW   -2
typedef  int  ElemType;
typedef  int  Status;

//----- 顺序表的顺序存储表示 -----
#define LIST_INIT_SIZE 100 // 存储空间的初始分配量
#define LISTINCREMENT 10 // 存储空间的分配增量
typedef struct {
	ElemType* elem;	// 存储空间的基址
	int length; // 表长
	int size;// 存储容量
	int increment; // 扩容时，增加的存储容量
} SqList;  //顺序表 

// 构造一个顺序表 
Status InitSqlist(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.size = LIST_INIT_SIZE;
	L.increment = LISTINCREMENT;
	return OK;
}
// 判顺序表是否为空表 
Status ListEmpty(SqList L) {
	if (L.length == 0) return OK;
	else return ERROR;
}
//顺序表插入函数
Status ListInsert_Sq(SqList& L, int i, ElemType e) {
	L.elem[i] = e;
}


//顺序表删除元素函数
Status ListDelete_Sq(SqList& L, int i, ElemType& e) {
	//请在此填写代码，将该算法补充完整，参见课本和课件相关章节
}

//输出顺序表函数
void OutList_Sq(SqList L)
{
	int i;
	ElemType  e;
	if (ListEmpty(L)) {
		printf("这是一个空表！");
	}
	else
	{
		printf("顺序表为：");
		for (i = 0; i < L.length; i++)
			printf("%6d", L.elem[i]);
	}
	printf("\n");
}
//主函数
int main()
{
	SqList L;
	int cord, i; ElemType a;
	printf("第一次使用必须初始化！\n");
	do {
		printf("\n 主菜单 \n");
		printf(" 1 初始化顺序表 ");
		printf(" 2 插入一个元素 ");
		printf(" 3 删除一个元素 ");
		printf(" 4 结束程序运行 ");
		printf("\n-------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			InitSqlist(L);
			OutList_Sq(L);
			break;
		case 2:
			printf("\n请输入要插入的插入位置和数据元素（如：3 20）");
			scanf("%d%d", &i, &a);
			ListInsert_Sq(L, i, a);
			printf("\n插入%d元素之后的", a);
			OutList_Sq(L);
			break;
		case 3:
			printf("\n请输入要删除的数据元素的位置（如： 3）");
			scanf("%d", &i);
			ListDelete_Sq(L, i, a);
			printf("\n删除第%d个位置的元素之后", i);
			OutList_Sq(L);
			break;
		case 4:
			exit(0);
		}
	} while (cord <= 4);
	return 1;
}
