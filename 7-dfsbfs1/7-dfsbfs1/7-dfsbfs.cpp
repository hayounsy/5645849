#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 11  // ��� ������ �����մϴ�.

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* graph[MAX_NODES];  // ���� ����Ʈ �׷����� ������ �迭

void add_edge(int start, int end) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = end;
    new_node->next = graph[start];
    graph[start] = new_node; // ��� �߰�
}

void bfs(int start, int target) {
    int visited[MAX_NODES] = { 0 }; // �湮 ���� �迭
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    queue[rear++] = start; // ���� ��� �߰�
    visited[start] = 1;

    printf("BFS ���: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node); // �湮�� ��� ���

        if (node == target) {
            printf("\nŽ�� ����!\n");
            return;
        }

        for (Node* temp = graph[node]; temp != NULL; temp = temp->next) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
        }
    }
    printf("\nŽ�� ����: Ÿ�� ��带 ã�� �� �����ϴ�.\n");
}

int dfs(int node, int target, int visited[]) {
    visited[node] = 1; // ���� ��� �湮 ǥ��
    printf("%d ", node); // �湮�� ��� ���

    if (node == target) {
        printf("\nŽ�� ����!\n");
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
    // �׷��� ����
    for (int i = 0; i < MAX_NODES; i++) {
        graph[i] = NULL;
    }

    // �׷����� ���� �߰�
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
    printf("��� ���: ");
    scanf("%d", &start_node);
    printf("Ž���� ��: ");
    scanf("%d", &target_node);

    printf("�ʺ� �켱 Ž��(BFS):\n");
    bfs(start_node, target_node);

    printf("���� �켱 Ž��(DFS):\n");
    int visited[MAX_NODES] = { 0 }; // DFS�� ���� �湮 �迭

    // DFS ȣ��
    if (!dfs(start_node, target_node, visited)) {
        printf("\nŽ�� ����: Ÿ�� ��带 ã�� �� �����ϴ�.\n");
    }

    // �޸� ����
    for (int i = 0; i < MAX_NODES; i++) {
        Node* current = graph[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp); // �Ҵ�� �޸� ����
        }
    }

    return 0;
}

