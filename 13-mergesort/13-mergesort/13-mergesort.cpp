#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// �� �� �̵� Ƚ���� �����ϱ� ���� ���� ����
int comparison_count = 0;
int move_count = 0;

// �պ� ������ �պ� �ܰ�
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // �ӽ� �迭 ����
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // ������ ����
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        move_count++;
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        move_count++;
    }

    // ����
    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparison_count++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
        move_count++;
    }

    // ���� ��� ����
    while (i < n1) {
        arr[k++] = L[i++];
        move_count++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
        move_count++;
    }

    // �޸� ����
    free(L);
    free(R);
}

// �պ� ������ ���� �ܰ�
void mergeSort(int arr[], int left, int right, int depth) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // ���� ����
        mergeSort(arr, left, mid, depth + 1);

        // ���� ����
        mergeSort(arr, mid + 1, right, depth + 1);

        // ����
        merge(arr, left, mid, right);

        // ���� ���� ��� (10�� ������ ���)
        if (depth <= 10) {
            printf("Depth %d: ", depth);
            for (int i = 0; i < SIZE; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
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

    // 20�� �ݺ��ϸ� ��� ���
    for (int t = 0; t < 20; t++) {
        // �迭 ����
        for (i = 0; i < SIZE; i++) {
            temp[i] = arr[i];
        }

        // ī��Ʈ �ʱ�ȭ
        comparison_count = 0;
        move_count = 0;

        // �պ� ���� ����
        mergeSort(temp, 0, SIZE - 1, 0);

        // �� Ƚ���� �̵� Ƚ�� ����
        total_comparisons += comparison_count;
        total_moves += move_count;
    }

    printf("\nSorted Array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    // ��� ���
    printf("\nAverage Comparisons: %d\n", total_comparisons / 20);
    printf("Average Moves: %d\n", total_moves / 20);

    return 0;
}
