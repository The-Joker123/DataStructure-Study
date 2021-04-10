#include"stdio.h"
#include"stdlib.h"
#define MaxInt 32767
#define MAX_VEX 20   //最大顶点个数
typedef enum { FALSE, TRUE } boolean;
typedef char VertexType;
typedef struct { //图的邻接矩阵存储结构
	VertexType vexs[MAX_VEX];   //顶点向量
	int arcs[MAX_VEX][MAX_VEX]; //邻接矩阵
	int vexnum, arcnum;   //图的当前顶点数和弧数
}MGraph;
boolean visited[MAX_VEX];   //访问标志数组

//图 G 中查找元素 c 的位置
int Locate(MGraph G, char c) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == c) return i;
	return -1;
}

//创建有向网的邻接矩阵存储结构
void CreateUDN(MGraph& G) {
	int i, j, w, s1, s2;
	char a, b, c, temp;
	printf("输入顶点数和弧数:");
	scanf("%d%d", &G.vexnum, &G.arcnum);
	temp = getchar();  //接收回车 
	printf("输入%d 个顶点（以空格做间隔）：\n", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {  //初始化顶点
		scanf("%c", &G.vexs[i]);
		temp = getchar();    //接收回车
	}
	for (i = 0; i < G.vexnum; i++)   //初始化邻接矩阵
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = MaxInt; //初始化弧
	printf("输入%d 条弧及其权值（以空格做间隔）：\n", G.arcnum);
	for (i = 0; i < G.arcnum; i++) {
		printf("输入弧%d:   ", i + 1);
		scanf("%c %c %d%c", &a, &b, &w, &c);//输入一条边依附的顶点和权值
		s1 = Locate(G, a); s2 = Locate(G, b); G.arcs[s1][s2] = w;
	}
}
//对连通图 G 深度优先遍历
void DFS(MGraph G, int v) {
	//请在此填写代码，将该算法补充完整，参见书本或课件相关章节


}

//  对非连通图 G 作深度优先遍历。
void DFSTraverse(MGraph G, int v) {
	//请在此填写代码，将该算法补充完整，参见书本或课件相关章节

}
//主函数
int main() {
	MGraph G;
	CreateUDN(G);
	printf("深度优先遍历: ");
	DFSTraverse(G, 0);
	printf("\n");
	return 0;
}