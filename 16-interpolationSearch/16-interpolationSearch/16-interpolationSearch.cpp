#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    return comparisons;
}

// ���� Ž�� �Լ�
int interpolation_search(int arr[], int size, int target) {
    int comparisons = 0;
    int low = 0, high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        comparisons++;
        if (low == high) {
            if (arr[low] == target) {
                return comparisons;
            }
            break;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);
        if (arr[pos] == target) {
            return comparisons;
        }
        else if (arr[pos] < target) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }
    return comparisons;
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
    int size = 1000;
    srand(time(NULL));

    // �迭 A ���� (0 ~ 9999 ������ ������ ��)
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }

    // �迭 ���� (�� ���� ���)
    quick_sort(arr, 0, size - 1);

    // ���ĵ� �迭�� ó�� 20�� ���
    printf("���ĵ� �迭�� ó�� 20��: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ���ĵ� �迭�� ������ 20�� ���
    printf("���ĵ� �迭�� ������ 20��: ");
    for (int i = size - 20; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ���� Ž�� 1000�� ���� �� ��� �� Ƚ�� ���
    int total_comparisons_binary = 0;
    for (int i = 0; i < 1000; i++) {
        int target = rand() % 10000;
        total_comparisons_binary += binary_search(arr, size, target);
    }
    double avg_comparisons_binary = total_comparisons_binary / 1000.0;
    printf("���� Ž�� ��� �� Ƚ��: %.2f\n", avg_comparisons_binary);

    // ���� Ž�� 1000�� ���� �� ��� �� Ƚ�� ���
    int total_comparisons_interpolation = 0;
    for (int i = 0; i < 1000; i++) {
        int target = rand() % 10000;
        total_comparisons_interpolation += interpolation_search(arr, size, target);
    }
    double avg_comparisons_interpolation = total_comparisons_interpolation / 1000.0;
    printf("���� Ž�� ��� �� Ƚ��: %.2f\n", avg_comparisons_interpolation);

    return 0;
}
