#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 허프만 트리 노드 구조체
struct Node {
    char character;
    int freq;
    struct Node* left, * right;
};

// 우선순위 큐를 위한 노드 구조체
struct MinHeapNode {
    int size;
    int capacity;
    struct Node** array;
};

// 새로운 허프만 노드 생성
struct Node* createNode(char character, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->left = newNode->right = NULL;
    newNode->character = character;
    newNode->freq = freq;
    return newNode;
}

// 우선순위 큐 생성
struct MinHeapNode* createMinHeap(int capacity) {
    struct MinHeapNode* minHeap = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(minHeap->capacity * sizeof(struct Node*));
    return minHeap;
}

// 두 노드의 빈도를 바탕으로 최소힙 구성
void swapNode(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeapNode* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// 최소 힙에서 최솟값 추출
struct Node* extractMin(struct MinHeapNode* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// 최소 힙에 새 노드 삽입
void insertMinHeap(struct MinHeapNode* minHeap, struct Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// 허프만 트리 생성
struct MinHeapNode* createHuffmanTree(char characters[], int freq[], int size) {
    struct Node* left, * right, * top;
    struct MinHeapNode* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(characters[i], freq[i]);

    minHeap->size = size;

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return minHeap;
}

// 허프만 코드 생성기
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {

    char characters[] = { 'a', 'e', 'i', 'o', 'u', 's', 't' };
    int freq[] = { 10, 15, 12, 3, 4, 13, 1 };
    int size = sizeof(characters) / sizeof(characters[0]);

    struct MinHeapNode* minHeap = createHuffmanTree(characters, freq, size);

    int arr[100], top = 0;

    printf("허프만 코드:\n");
    printCodes(minHeap->array[0], arr, top);

    return 0;
    }
