#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// 비교 및 이동 횟수를 저장하기 위한 전역 변수
int comparison_count = 0;
int move_count = 0;

// 합병 정렬의 합병 단계
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 임시 배열 생성
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // 데이터 복사
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        move_count++;
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        move_count++;
    }

    // 병합
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

    // 남은 요소 복사
    while (i < n1) {
        arr[k++] = L[i++];
        move_count++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
        move_count++;
    }

    // 메모리 해제
    free(L);
    free(R);
}

// 합병 정렬의 분할 단계
void mergeSort(int arr[], int left, int right, int depth) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 좌측 정렬
        mergeSort(arr, left, mid, depth + 1);

        // 우측 정렬
        mergeSort(arr, mid + 1, right, depth + 1);

        // 병합
        merge(arr, left, mid, right);

        // 정렬 상태 출력 (10번 단위로 출력)
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

    // 랜덤 데이터 생성
    srand(time(0));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Original Array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // 20번 반복하며 평균 계산
    for (int t = 0; t < 20; t++) {
        // 배열 복사
        for (i = 0; i < SIZE; i++) {
            temp[i] = arr[i];
        }

        // 카운트 초기화
        comparison_count = 0;
        move_count = 0;

        // 합병 정렬 실행
        mergeSort(temp, 0, SIZE - 1, 0);

        // 비교 횟수와 이동 횟수 누적
        total_comparisons += comparison_count;
        total_moves += move_count;
    }

    printf("\nSorted Array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    // 평균 출력
    printf("\nAverage Comparisons: %d\n", total_comparisons / 20);
    printf("Average Moves: %d\n", total_moves / 20);

    return 0;
}
