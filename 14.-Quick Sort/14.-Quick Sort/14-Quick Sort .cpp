#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// ���� ����: �� Ƚ�� �� �̵� Ƚ��
int comparison_count = 0;
int move_count = 0;

// �� ������ ��Ƽ�� �Լ�
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparison_count++;
        if (arr[j] <= pivot) {
            i++;
            // swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            move_count += 3; // 3�� �̵�
        }
    }

    // pivot�� i+1 ��ġ�� �� ��ȯ
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    move_count += 3; // 3�� �̵�

    return i + 1;
}

// �� ���� �Լ� (����� ����)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // ���� �������� 40~60 �ε��� ���
        if (low <= 40 && high >= 60) {
            printf("Current array (40~60 indices): ");
            for (int i = 40; i <= 60; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        // ��� ȣ��
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[SIZE], temp[SIZE];
    int i, total_comparisons = 0, total_moves = 0;

    // ���� ������ ����
    srand(time(0));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Original Array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // 20�� �ݺ��Ͽ� ��� ���
    for (int t = 0; t < 20; t++) {
        // �迭 ����
        for (i = 0; i < SIZE; i++) {
            temp[i] = arr[i];
        }

        // ī��Ʈ �ʱ�ȭ
        comparison_count = 0;
        move_count = 0;

        // �� ���� ����
        quickSort(temp, 0, SIZE - 1);

        // �� Ƚ���� �̵� Ƚ�� ����
        total_comparisons += comparison_count;
        total_moves += move_count;
    }

    printf("\nSorted Array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ��� ���
    printf("\nAverage Comparisons: %d\n", total_comparisons / 20);
    printf("Average Moves: %d\n", total_moves / 20);

    return 0;
}
