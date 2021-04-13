#include"stdio.h"
#include"stdlib.h"
#define MaxInt 32767
#define MAX_VEX 20  //最大顶点个数
#define QUEUE_SIZE (MAX_VEX+1) //队列长度
typedef enum { FALSE, TRUE } boolean;
typedef char VertexType;
typedef struct {  //图的邻接矩阵存储结构
    VertexType vexs[MAX_VEX]; //顶点向量
    int arcs[MAX_VEX][MAX_VEX];  //邻接矩阵
    int vexnum, arcnum;  //图的当前顶点数和弧数
}MGraph;
boolean visited[MAX_VEX];  //访问标志数组
typedef struct {
    int    data[MAX_VEX];
    int    front, rear;
}Queue;
void InitQueue(Queue* Q) {
    Q->front = Q->rear = 0;
}
void EnQueue(Queue* Q, int e) {
    if ((Q->rear + 1) % MAX_VEX == Q->front)
        return;

    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_VEX;
}
//判空
boolean QueueEmpty(Queue* Q)
{
    if (Q->front == Q->rear)
        return TRUE;
    else
        return FALSE;
}
void DeQueue(Queue* Q, int* e) {

    if (Q->front == Q->rear)
        return;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_VEX;
}
//图 G 中查找元素 c 的位置
int Locate(MGraph G, char c) {
    for (int i = 0; i < G.vexnum; i++)
        if (G.vexs[i] == c) return i;
    return -1;
}
//创建无向网的邻接矩阵存储结构
void CreateUDN(MGraph& G) {
    int i, j, w, s1, s2;
    char a, b, c, temp;
    printf("输入顶点数和弧数:");
    scanf("%d%d", &G.vexnum, &G.arcnum);
    temp = getchar();   //接收回车
    printf("输入%d 个顶点（以空格做间隔）：\n", G.vexnum);
    for (i = 0; i < G.vexnum; i++) { //初始化顶点
        scanf("%c", &G.vexs[i]);
        temp = getchar(); //接收回车
    }
    for (i = 0; i < G.vexnum; i++)                                                       //初始化邻接矩阵
        for (j = 0; j < G.vexnum; j++) G.arcs[i][j] = MaxInt;
    printf("输入%d 条弧及其权值（以空格做间隔）：\n", G.arcnum);
    for (i = 0; i < G.arcnum; i++) {                                                  //初始化弧
        printf("输入弧%d:    ", i + 1);
        scanf("%c %c %d%c", &a, &b, &w, &c);       //输入一条边依附的顶点和权值
        s1 = Locate(G, a);
        s2 = Locate(G, b); G.arcs[s1][s2] = G.arcs[s2][s1] = w;
    }
}
//广度优先遍历
void BFS(MGraph G) {
    //请在此填写代码，将该算法补充完整，参见书本或课件相关章节
    //按广度优先遍历图G，使用辅助队列Q和访问标志数组
    int i, j;
    Queue Q;
    for (i = 0; i < G.vexnum; ++i)
        visited[i] = FALSE;//初始所有顶点状态都是未访问过状态
    InitQueue(&Q);//初始化辅助用的队列 
    for (i = 0; i < G.vexnum; ++i) //对每一个顶点做循环 
        if (!visited[i])//若是未访问过就处理 
        {
            visited[i] = TRUE;//设置当前顶点访问过 
            printf("%c ", G.vexs[i]);//打印顶点 
            EnQueue(&Q, i);//将此顶点入队列 
            while (!QueueEmpty(&Q))//判断队列是否为空 ，如果为空返回TRUE 
            {
                DeQueue(&Q, &i);//若队列非空，进行出队操作 ，赋值给i 
                for (j = 0; j < G.vexnum; ++j)
                {

                    if (!visited[j] && G.arcs[i][j] != MaxInt)//判断顶点没有被访问过并且邻接矩阵的值不是无穷大 
                    {
                        visited[j] = TRUE;//标记该顶点被访问，打印该顶点然后执行入队操作 
                        printf("->");
                        printf("%c ", G.vexs[j]);//打印顶点
                        EnQueue(&Q, j);//将找到的此顶点入队列 
                    }
                }
            }
        }
}

//主函数
int  main() {
    MGraph G; CreateUDN(G);
    printf("广度优先遍历: ");
    BFS(G);
    printf("\n");
    return 0;
}

