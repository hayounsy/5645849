#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 10  // 그래프의 정점 개수 (필요에 따라 변경)

// 최소 가중치의 간선을 찾는 함수
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// MST를 출력하는 함수
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Prim 알고리즘을 사용하여 MST를 찾는 함수
void primMST(int graph[V][V]) {
    int parent[V];   // MST를 구성하는 간선을 저장
    int key[V];      // 최소 가중치를 저장
    bool mstSet[V];  // MST에 포함된 정점을 표시

    // 초기화
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // 시작 정점 선택
    key[0] = 0;
    parent[0] = -1;

    // MST의 각 정점 선택
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        // 선택된 정점과 인접한 정점의 가중치 갱신
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    // MST 출력
    printMST(parent, graph);
}

int main() {
    // 그래프의 가중치 인접 행렬
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

    // MST 생성
    primMST(graph);

    return 0;
}
