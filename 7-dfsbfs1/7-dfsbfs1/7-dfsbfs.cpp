#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 11  // 노드 개수를 정의합니다.

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* graph[MAX_NODES];  // 인접 리스트 그래프를 저장할 배열

void add_edge(int start, int end) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = end;
    new_node->next = graph[start];
    graph[start] = new_node; // 노드 추가
}

void bfs(int start, int target) {
    int visited[MAX_NODES] = { 0 }; // 방문 여부 배열
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    queue[rear++] = start; // 시작 노드 추가
    visited[start] = 1;

    printf("BFS 경로: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node); // 방문한 노드 출력

        if (node == target) {
            printf("\n탐색 성공!\n");
            return;
        }

        for (Node* temp = graph[node]; temp != NULL; temp = temp->next) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
        }
    }
    printf("\n탐색 실패: 타겟 노드를 찾을 수 없습니다.\n");
}

int dfs(int node, int target, int visited[]) {
    visited[node] = 1; // 현재 노드 방문 표시
    printf("%d ", node); // 방문한 노드 출력

    if (node == target) {
        printf("\n탐색 성공!\n");
        return 1;
    }

    for (Node* temp = graph[node]; temp != NULL; temp = temp->next) {
        if (!visited[temp->data]) {
            if (dfs(temp->data, target, visited)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    // 그래프 정의
    for (int i = 0; i < MAX_NODES; i++) {
        graph[i] = NULL;
    }

    // 그래프의 간선 추가
    add_edge(0, 5);
    add_edge(0, 9);
    add_edge(0, 2);
    add_edge(0, 6);
    add_edge(0, 4);
    add_edge(9, 0);
    add_edge(9, 6);
    add_edge(9, 8);
    add_edge(5, 0);
    add_edge(5, 3);
    add_edge(5, 4);
    add_edge(5, 1);
    add_edge(1, 5);
    add_edge(1, 4);
    add_edge(1, 7);
    add_edge(1, 10);
    add_edge(2, 0);
    add_edge(2, 3);
    add_edge(2, 4);
    add_edge(3, 2);
    add_edge(3, 4);
    add_edge(3, 5);
    add_edge(4, 2);
    add_edge(4, 3);
    add_edge(4, 6);
    add_edge(4, 1);
    add_edge(4, 7);
    add_edge(6, 0);
    add_edge(6, 4);
    add_edge(6, 7);
    add_edge(6, 8);
    add_edge(7, 1);
    add_edge(7, 4);
    add_edge(7, 6);
    add_edge(7, 10);
    add_edge(8, 9);
    add_edge(8, 6);
    add_edge(8, 10);
    add_edge(10, 1);
    add_edge(10, 7);
    add_edge(10, 8);

    int start_node, target_node;
    printf("출발 노드: ");
    scanf("%d", &start_node);
    printf("탐색할 값: ");
    scanf("%d", &target_node);

    printf("너비 우선 탐색(BFS):\n");
    bfs(start_node, target_node);

    printf("깊이 우선 탐색(DFS):\n");
    int visited[MAX_NODES] = { 0 }; // DFS를 위한 방문 배열

    // DFS 호출
    if (!dfs(start_node, target_node, visited)) {
        printf("\n탐색 실패: 타겟 노드를 찾을 수 없습니다.\n");
    }

    // 메모리 해제
    for (int i = 0; i < MAX_NODES; i++) {
        Node* current = graph[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp); // 할당된 메모리 해제
        }
    }

    return 0;
}

