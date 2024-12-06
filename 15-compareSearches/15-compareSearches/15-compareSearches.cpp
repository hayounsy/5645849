#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���� Ž�� �Լ�
int sequential_search(int arr[], int size, int target) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == target) {
            return comparisons;
        }
    }
    return comparisons; // Ÿ���� ������ �� Ƚ���� ��ȯ
}

// ���� Ž�� �Լ�
int binary_search(int arr[], int size, int target) {
    int comparisons = 0;
    int left = 0, right = size - 1;
    while (left <= right) {
        comparisons++;
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return comparisons;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return comparisons; // Ÿ���� ������ �� Ƚ���� ��ȯ
}

// �� ���� �Լ�
void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[left];
    int i = left + 1, j = right;
    while (i <= j) {
        while (i <= right && arr[i] <= pivot) i++;
        while (j > left && arr[j] >= pivot) j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

int main() {
    int arr[1000];
    int sorted_arr[1000];
    int size = 1000;
    int total_comparisons_sequential = 0, total_comparisons_binary = 0;
    srand(time(NULL));

    // �迭 ���� (0~999 ������ ������ ��)
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }

    // ���� Ž�� 100ȸ ��� �� Ƚ�� ���
    for (int i = 0; i < 100; i++) {
        int target = rand() % 1000;
        total_comparisons_sequential += sequential_search(arr, size, target);
    }
    double avg_comparisons_sequential = total_comparisons_sequential / 100.0;
    printf("��� ���� Ž�� �� Ƚ�� (A): %.2f\n", avg_comparisons_sequential);

    // �迭 ���� �� �� ����
    for (int i = 0; i < size; i++) {
        sorted_arr[i] = arr[i];
    }
    quick_sort(sorted_arr, 0, size - 1);

    // ���ĵ� �迭�� ���� ���� Ž�� 100ȸ ��� �� Ƚ�� ���
    for (int i = 0; i < 100; i++) {
        int target = rand() % 1000;
        total_comparisons_binary += binary_search(sorted_arr, size, target);
    }
    double avg_comparisons_binary = total_comparisons_binary / 100.0;
    printf("��� ���� Ž�� �� Ƚ�� (C): %.2f\n", avg_comparisons_binary);

    // �迭 ���
    printf("���ĵ� �迭�� ó�� 20��: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    printf("���ĵ� �迭�� ������ 20��: ");
    for (int i = size - 20; i < size; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    return 0;
}
