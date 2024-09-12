#include <stdio.h>
#include <stdlib.h>

// 1. 노드 구조 정의 (링크 트리 용)
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// 새로운 노드를 생성하는 함수 (링크 트리 용)
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 2. 배열 기반 트리 구성
int treeArray[15];

void GenerateArrayTree() {
    // 트리 배열 구성 (배열 인덱스는 0부터 시작하므로, 1부터 15까지 배열에 맞게 넣음)
    treeArray[0] = 1;
    treeArray[1] = 2;
    treeArray[2] = 9;
    treeArray[3] = 3;
    treeArray[4] = 5;
    treeArray[5] = 10;
    treeArray[6] = 13;
    treeArray[7] = 4;
    treeArray[8] = 6;
    treeArray[9] = 7;
    treeArray[10] = 8;
    treeArray[11] = 11;
    treeArray[12] = 12;
    treeArray[13] = 14;
    treeArray[14] = 15;
}

// 배열 기반 전위 순회
void ArrayPreorder(int index, int size) {
    if (index >= size || treeArray[index] == 0) return;
    printf("%d ", treeArray[index]);
    ArrayPreorder(2 * index + 1, size); // 왼쪽 자식
    ArrayPreorder(2 * index + 2, size); // 오른쪽 자식
}

// 배열 기반 중위 순회
void ArrayInorder(int index, int size) {
    if (index >= size || treeArray[index] == 0) return;
    ArrayInorder(2 * index + 1, size); // 왼쪽 자식
    printf("%d ", treeArray[index]);
    ArrayInorder(2 * index + 2, size); // 오른쪽 자식
}

// 배열 기반 후위 순회
void ArrayPostorder(int index, int size) {
    if (index >= size || treeArray[index] == 0) return;
    ArrayPostorder(2 * index + 1, size); // 왼쪽 자식
    ArrayPostorder(2 * index + 2, size); // 오른쪽 자식
    printf("%d ", treeArray[index]);
}

void ArrayOrders() {
    int size = 15;
    printf("Array Preorder: ");
    ArrayPreorder(0, size);
    printf("\n");

    printf("Array Inorder: ");
    ArrayInorder(0, size);
    printf("\n");

    printf("Array Postorder: ");
    ArrayPostorder(0, size);
    printf("\n");
}

// 3. 링크 기반 트리 구성
struct Node* GenerateLinkTree() {
    struct Node* node1 = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(4);
    struct Node* node5 = createNode(5);
    struct Node* node6 = createNode(6);
    struct Node* node7 = createNode(7);
    struct Node* node8 = createNode(8);
    struct Node* node9 = createNode(9);
    struct Node* node10 = createNode(10);
    struct Node* node11 = createNode(11);
    struct Node* node12 = createNode(12);
    struct Node* node13 = createNode(13);
    struct Node* node14 = createNode(14);
    struct Node* node15 = createNode(15);

    // 노드 연결 (주어진 트리 구조에 맞게)
    node1->left = node2;
    node1->right = node9;

    node2->left = node3;
    node2->right = node5;

    node3->left = node4;
    node3->right = node6;

    node5->left = node7;
    node5->right = node8;

    node9->left = node10;
    node9->right = node13;

    node10->left = node11;
    node10->right = node12;

    node13->left = node14;
    node13->right = node15;

    return node1;  // 루트 노드 반환
}

// 링크 기반 전위 순회
void LinkPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    LinkPreorder(node->left);
    LinkPreorder(node->right);
}

// 링크 기반 중위 순회
void LinkInorder(struct Node* node) {
    if (node == NULL) return;
    LinkInorder(node->left);
    printf("%d ", node->data);
    LinkInorder(node->right);
}

// 링크 기반 후위 순회
void LinkPostorder(struct Node* node) {
    if (node == NULL) return;
    LinkPostorder(node->left);
    LinkPostorder(node->right);
    printf("%d ", node->data);
}

void LinkOrders(struct Node* root) {
    printf("Link Preorder: ");
    LinkPreorder(root);
    printf("\n");

    printf("Link Inorder: ");
    LinkInorder(root);
    printf("\n");

    printf("Link Postorder: ");
    LinkPostorder(root);
    printf("\n");
}

int main() {
    // 4. 배열 기반 트리 구성 및 순회
    GenerateArrayTree();
    ArrayOrders();  // 배열 기반 순회 수행

    // 5. 링크 기반 트리 구성 및 순회
    struct Node* root = GenerateLinkTree();
    LinkOrders(root);  // 링크 기반 순회 수행

    return 0;
}
