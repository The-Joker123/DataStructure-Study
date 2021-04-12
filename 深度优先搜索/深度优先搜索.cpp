#include"stdio.h"
#include"stdlib.h"
#define MaxInt 32767
#define MAX_VEX 20   //��󶥵����
typedef enum { FALSE, TRUE } boolean;
typedef char VertexType;
typedef struct { //ͼ���ڽӾ���洢�ṹ
	VertexType vexs[MAX_VEX];   //��������
	int arcs[MAX_VEX][MAX_VEX]; //�ڽӾ���
	char str[MAX_VEX][MAX_VEX];
	int vexnum, arcnum;   //ͼ�ĵ�ǰ�������ͻ���
}MGraph;
boolean visited[MAX_VEX];   //���ʱ�־����

//ͼ G �в���Ԫ�� c ��λ��
int Locate(MGraph G, char c) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == c) return i;
	return -1;
}

//�������������ڽӾ���洢�ṹ
void CreateUDN(MGraph& G) {
	int i, j, w, s1, s2;
	char a, b, c, temp;
	printf("���붥�����ͻ���:");
	scanf("%d%d", &G.vexnum, &G.arcnum);
	temp = getchar();  //���ջس� 
	printf("����%d �����㣨�Կո����������\n", G.vexnum);
	for (i = 0; i < G.vexnum; i++) {  //��ʼ������
		scanf("%c", &G.vexs[i]);
		temp = getchar();    //���ջس�
	}
	for (i = 0; i < G.vexnum; i++)   //��ʼ���ڽӾ���
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = MaxInt; //��ʼ����
			G.str[i][j] ='x';
	printf("����%d ��������Ȩֵ���Կո����������\n", G.arcnum);
	for (i = 0; i < G.arcnum; i++) {
		printf("���뻡%d:   ", i + 1);
		scanf("%c %c %d%c", &a, &b, &w, &c);//����һ���������Ķ����Ȩֵ
		s1 = Locate(G, a); s2 = Locate(G, b); G.arcs[s1][s2] = w; G.str[s1][s2] = char(w);
	}
	
	for (i = 0; i < G.vexnum; i++)
	{

		for (j = 0; j < G.vexnum; j++)
		{
			printf(" %d ", G.str[i][j]);
		}
		printf("\n");
			 //��ӡ���ڽӾ���
	}
	
}
//����ͨͼ G ������ȱ���
void DFS(MGraph G, int v) {
	int j;
	visited[v] = TRUE;
	printf("->%c", G.vexs[v]);
	for (j = 0; j < G.vexnum; j++)
	{
		if (G.arcs[v][j] == 1 && !visited[j])
		{
			DFS(G, j);
		}
	}

}

//  �Է���ͨͼ G ��������ȱ�����
void DFSTraverse(MGraph G, int v) {
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		visited[v] = FALSE;
	}
	for (i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			DFS(G, i);
		}
	}

}
//������
int main() {
	MGraph G;
	CreateUDN(G);
	printf("������ȱ���: ");
	DFSTraverse(G, 0);
	printf("\n");
	return 0;
}