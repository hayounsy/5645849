#include <stdio.h>
#include <stdlib.h>

// 이진 탐색 트리 노드 정의
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 새 노드 생성
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 이진 탐색 트리에 삽입
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// 중위 순회(Inorder Traversal)
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int values[] = {4, 1, 9, 13, 15, 3, 6, 14, 7, 10, 12, 2, 5, 8, 11};
    int n = sizeof(values) / sizeof(values[0]);

    // 이진 탐색 트리에 값 추가
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // 중위 순회 출력
    printf("BST 중위순회 결과: ");
    inorder(root);
    printf("\n");

    return 0;
}
//스레드 이진트리 구성 및 중위순회
/
#include <stdio.h>
#include <stdlib.h>

// 스레드 이진트리 노드 정의
typedef struct ThreadedNode {
    int data;
    struct ThreadedNode* left;
    struct ThreadedNode* right;
    int leftThread;
    int rightThread;
} ThreadedNode;

// 새 스레드 노드 생성
ThreadedNode* createThreadedNode(int data) {
    ThreadedNode* newNode = (ThreadedNode*)malloc(sizeof(ThreadedNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 1;
    newNode->rightThread = 1;
    return newNode;
}

// 스레드 이진트리에 삽입
ThreadedNode* insertThreaded(ThreadedNode* root, int data) {
    if (root == NULL)
        return createThreadedNode(data);

    ThreadedNode* parent = NULL;
    ThreadedNode* current = root;

    // 삽입 위치 찾기
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            if (current->leftThread == 0)
                current = current->left;
            else
                break;
        } else {
            if (current->rightThread == 0)
                current = current->right;
            else
                break;
        }
    }

    // 새로운 노드 삽입
    ThreadedNode* newNode = createThreadedNode(data);
    if (data < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = 0;
        parent->left = newNode;
    } else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rightThread = 0;
        parent->right = newNode;
    }
    return root;
}

// 가장 왼쪽 노드 찾기
ThreadedNode* leftmost(ThreadedNode* node) {
    if (node == NULL)
        return NULL;
    while (node->leftThread == 0)
        node = node->left;
    return node;
}

// 스레드 이진트리 중위 순회 (스택 없이 반복)
void inorderThreaded(ThreadedNode* root) {
    ThreadedNode* current = leftmost(root);
    while (current != NULL) {
        printf("%d ", current->data);

        if (current->rightThread == 1)
            current = current->right;
        else
            current = leftmost(current->right);
    }
}

int main() {
    ThreadedNode* root = NULL;
    int values[] = {4, 1, 9, 13, 15, 3, 6, 14, 7, 10, 12, 2, 5, 8, 11};
    int n = sizeof(values) / sizeof(values[0]);

    // 스레드 이진트리에 값 추가
    for (int i = 0; i < n; i++) {
        root = insertThreaded(root, values[i]);
    }

    // 스레드 이진트리 중위순회 출력
    printf("스레드 이진트리 중위순회 결과: ");
    inorderThreaded(root);
    printf("\n");

    return 0;
}

/
