#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 10  // �׷����� ���� ���� (�ʿ信 ���� ����)

// �ּ� ����ġ�� ������ ã�� �Լ�
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// MST�� ����ϴ� �Լ�
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Prim �˰����� ����Ͽ� MST�� ã�� �Լ�
void primMST(int graph[V][V]) {
    int parent[V];   // MST�� �����ϴ� ������ ����
    int key[V];      // �ּ� ����ġ�� ����
    bool mstSet[V];  // MST�� ���Ե� ������ ǥ��

    // �ʱ�ȭ
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // ���� ���� ����
    key[0] = 0;
    parent[0] = -1;

    // MST�� �� ���� ����
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        // ���õ� ������ ������ ������ ����ġ ����
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    // MST ���
    printMST(parent, graph);
}

int main() {
    // �׷����� ����ġ ���� ���
    int graph[V][V] = {
        {0, 12, 0, 0, 0, 11, 0, 8, 0, 0},
        {12, 0, 3, 8, 7, 0, 0, 6, 0, 0},
        {0, 3, 0, 5, 0, 0, 2, 0, 0, 0},
        {0, 8, 5, 0, 4, 0, 0, 0, 14, 0},
        {0, 7, 0, 4, 0, 1, 9, 0, 0, 18},
        {11, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 9, 0, 0, 0, 0, 0},
        {8, 6, 0, 0, 0, 0, 0, 0, 15, 0},
        {0, 0, 0, 14, 0, 0, 0, 15, 0, 10},
        {0, 0, 0, 0, 18, 0, 0, 0, 10, 0}
    };

    // MST ����
    primMST(graph);

    return 0;
}
