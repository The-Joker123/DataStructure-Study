#include"stdio.h"
#include"stdlib.h"
#define MaxInt 32767
#define MAX_VEX 20  //��󶥵����
#define QUEUE_SIZE (MAX_VEX+1) //���г���
typedef enum { FALSE, TRUE } boolean;
typedef char VertexType;
typedef struct {  //ͼ���ڽӾ���洢�ṹ
    VertexType vexs[MAX_VEX]; //��������
    int arcs[MAX_VEX][MAX_VEX];  //�ڽӾ���
    int vexnum, arcnum;  //ͼ�ĵ�ǰ�������ͻ���
}MGraph;
boolean visited[MAX_VEX];  //���ʱ�־����
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
//�п�
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
    temp = getchar();   //���ջس�
    printf("����%d �����㣨�Կո����������\n", G.vexnum);
    for (i = 0; i < G.vexnum; i++) { //��ʼ������
        scanf("%c", &G.vexs[i]);
        temp = getchar(); //���ջس�
    }
    for (i = 0; i < G.vexnum; i++)                                                       //��ʼ���ڽӾ���
        for (j = 0; j < G.vexnum; j++) G.arcs[i][j] = MaxInt;
    printf("����%d ��������Ȩֵ���Կո����������\n", G.arcnum);
    for (i = 0; i < G.arcnum; i++) {                                                  //��ʼ����
        printf("���뻡%d:    ", i + 1);
        scanf("%c %c %d%c", &a, &b, &w, &c);       //����һ���������Ķ����Ȩֵ
        s1 = Locate(G, a);
        s2 = Locate(G, b); G.arcs[s1][s2] = G.arcs[s2][s1] = w;
    }
}
//������ȱ���
void BFS(MGraph G) {
    //���ڴ���д���룬�����㷨�����������μ��鱾��μ�����½�
    //��������ȱ���ͼG��ʹ�ø�������Q�ͷ��ʱ�־����
    int i, j;
    Queue Q;
    for (i = 0; i < G.vexnum; ++i)
        visited[i] = FALSE;//��ʼ���ж���״̬����δ���ʹ�״̬
    InitQueue(&Q);//��ʼ�������õĶ��� 
    for (i = 0; i < G.vexnum; ++i) //��ÿһ��������ѭ�� 
        if (!visited[i])//����δ���ʹ��ʹ��� 
        {
            visited[i] = TRUE;//���õ�ǰ������ʹ� 
            printf("%c ", G.vexs[i]);//��ӡ���� 
            EnQueue(&Q, i);//���˶�������� 
            while (!QueueEmpty(&Q))//�ж϶����Ƿ�Ϊ�� �����Ϊ�շ���TRUE 
            {
                DeQueue(&Q, &i);//�����зǿգ����г��Ӳ��� ����ֵ��i 
                for (j = 0; j < G.vexnum; ++j)
                {

                    if (!visited[j] && G.arcs[i][j] != MaxInt)//�ж϶���û�б����ʹ������ڽӾ����ֵ��������� 
                    {
                        visited[j] = TRUE;//��Ǹö��㱻���ʣ���ӡ�ö���Ȼ��ִ����Ӳ��� 
                        printf("->");
                        printf("%c ", G.vexs[j]);//��ӡ����
                        EnQueue(&Q, j);//���ҵ��Ĵ˶�������� 
                    }
                }
            }
        }
}

//������
int  main() {
    MGraph G; CreateUDN(G);
    printf("������ȱ���: ");
    BFS(G);
    printf("\n");
    return 0;
}

