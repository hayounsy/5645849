#include <stdio.h>
#define INF 99999
#define MAX 12

int graph[MAX][MAX] = {
    {0, 12, INF, INF, INF, 11, INF, 8, INF, INF, INF, INF},
    {12, 0, 3, 8, INF, INF, 9, INF, INF, INF, INF, INF},
    {INF, 3, 0, 2, 4, INF, 7, 5, INF, INF, INF, INF},
    {INF, 8, 2, 0, 13, 1, INF, 6, 16, INF, INF, INF},
    {INF, INF, 4, 13, 0, 18, INF, INF, 17, 10, INF, INF},
    {11, INF, INF, 1, 18, 0, INF, INF, INF, INF, 14, INF},
    {INF, 9, 7, INF, INF, INF, 0, INF, INF, INF, 6, INF},
    {8, INF, 5, 6, INF, INF, INF, 0, INF, INF, 15, INF},
    {INF, INF, INF, 16, 17, INF, INF, INF, 0, INF, 5, INF},
    {INF, INF, INF, INF, 10, INF, INF, INF, INF, 0, 8, INF},
    {INF, INF, INF, INF, INF, INF, 6, 15, 5, 8, 0, INF},
    {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0}
};

int visited[MAX] = { 0 }; // 방문 여부 체크
int dist[MAX]; // 최단 거리

int findMinVertex(int n) {
    int min = INF, minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int n, int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = findMinVertex(n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int startVertex = 0; // 1번 정점 (index 0)
    dijkstra(MAX, startVertex);

    printf("1번 정점으로부터 각 정점까지의 최단 거리:\n");
    for (int i = 0; i < MAX; i++) {
        printf("정점 %d까지의 거리: %d\n", i + 1, dist[i]);
    }
    return 0;
}
