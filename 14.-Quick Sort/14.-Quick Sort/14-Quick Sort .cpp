#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// 전역 변수: 비교 횟수 및 이동 횟수
int comparison_count = 0;
int move_count = 0;

// 퀵 정렬의 파티션 함수
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
            move_count += 3; // 3번 이동
        }
    }

    // pivot과 i+1 위치의 값 교환
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    move_count += 3; // 3번 이동

    return i + 1;
}

// 퀵 정렬 함수 (재귀적 구현)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // 정렬 과정에서 40~60 인덱스 출력
        if (low <= 40 && high >= 60) {
            printf("Current array (40~60 indices): ");
            for (int i = 40; i <= 60; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        // 재귀 호출
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // 20번 반복하여 평균 계산
    for (int t = 0; t < 20; t++) {
        // 배열 복사
        for (i = 0; i < SIZE; i++) {
            temp[i] = arr[i];
        }

        // 카운트 초기화
        comparison_count = 0;
        move_count = 0;

        // 퀵 정렬 실행
        quickSort(temp, 0, SIZE - 1);

        // 비교 횟수와 이동 횟수 누적
        total_comparisons += comparison_count;
        total_moves += move_count;
    }

    printf("\nSorted Array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 평균 출력
    printf("\nAverage Comparisons: %d\n", total_comparisons / 20);
    printf("Average Moves: %d\n", total_moves / 20);

    return 0;
}
