#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 노드 구조체 정의
typedef struct Node {
    int key;
    struct Node* left, * right;
} Node;

typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode* left, * right;
} AVLNode;

int compareCount = 0;
int searchCount = 0;

// BST 노드 생성
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// AVL 노드 생성
AVLNode* createAVLNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

// BST 삽입
Node* insertBST(Node* root, int key) {
    compareCount++;
    if (root == NULL) return createNode(key);

    if (key < root->key)
        root->left = insertBST(root->left, key);
    else if (key > root->key)
        root->right = insertBST(root->right, key);

    return root;
}

// AVL 유틸리티 함수
int height(AVLNode* node) {
    return node ? node->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* insertAVL(AVLNode* node, int key) {
    compareCount++;
    if (node == NULL) return createAVLNode(key);

    if (key < node->key)
        node->left = insertAVL(node->left, key);
    else if (key > node->key)
        node->right = insertAVL(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void freeAVLTree(AVLNode* root) {
    if (root) {
        freeAVLTree(root->left);
        freeAVLTree(root->right);
        free(root);
    }
}

void doAVLBatch(AVLNode** root) {
    for (int i = 0; i < 2000; i++) {
        int A = rand() % 3;
        int B = rand() % 1000;

        if (A == 0) {
            *root = insertAVL(*root, B);
        }
        else if (A == 2) {
            searchCount++;
        }
    }
}

void doBinaryBatch(Node** root) {
    for (int i = 0; i < 2000; i++) {
        int A = rand() % 3;
        int B = rand() % 1000;

        if (A == 0) {
            *root = insertBST(*root, B);
        }
        else if (A == 2) {
            searchCount++;
        }
    }
}

int main(int argc, char* argv[]) {
    Node* root = NULL;
    AVLNode* avlRoot = NULL;
    srand(time(NULL));
    float allCount = 0.0;

    // AVL 트리 작업 수행
    doAVLBatch(&avlRoot);
    allCount = (float)compareCount / searchCount;
    printf("average AVL compare count: %.2f\n", allCount);

    freeAVLTree(avlRoot);
    avlRoot = NULL;
    compareCount = 0;
    searchCount = 0;

    // 이진 탐색 트리 작업 수행
    doBinaryBatch(&root);
    allCount = (float)compareCount / searchCount;
    printf("average Bin compare count: %.2f\n", allCount);

    freeTree(root);
    return 0;
}

