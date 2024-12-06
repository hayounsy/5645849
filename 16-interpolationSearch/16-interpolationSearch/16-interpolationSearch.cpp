#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 이진 탐색 함수
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

// 보간 탐색 함수
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

// 퀵 정렬 함수
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

    // 배열 A 생성 (0 ~ 9999 사이의 임의의 수)
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }

    // 배열 정렬 (퀵 정렬 사용)
    quick_sort(arr, 0, size - 1);

    // 정렬된 배열의 처음 20개 출력
    printf("정렬된 배열의 처음 20개: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 정렬된 배열의 마지막 20개 출력
    printf("정렬된 배열의 마지막 20개: ");
    for (int i = size - 20; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 이진 탐색 1000번 실행 및 평균 비교 횟수 계산
    int total_comparisons_binary = 0;
    for (int i = 0; i < 1000; i++) {
        int target = rand() % 10000;
        total_comparisons_binary += binary_search(arr, size, target);
    }
    double avg_comparisons_binary = total_comparisons_binary / 1000.0;
    printf("이진 탐색 평균 비교 횟수: %.2f\n", avg_comparisons_binary);

    // 보간 탐색 1000번 실행 및 평균 비교 횟수 계산
    int total_comparisons_interpolation = 0;
    for (int i = 0; i < 1000; i++) {
        int target = rand() % 10000;
        total_comparisons_interpolation += interpolation_search(arr, size, target);
    }
    double avg_comparisons_interpolation = total_comparisons_interpolation / 1000.0;
    printf("보간 탐색 평균 비교 횟수: %.2f\n", avg_comparisons_interpolation);

    return 0;
}
