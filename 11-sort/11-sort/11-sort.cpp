#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// 선택 정렬 함수
void selectionSort(int arr[], int n) {
    int i, j, min_idx, step = 0;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        // 10단위로 출력
        step++;
        if (step % 10 == 0) {
            printf("Step %d: ", step);
            for (int k = 0; k < n; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }
}

// 삽입 정렬 함수
int insertionSort(int arr[], int n) {
    int i, key, j, comparisons = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = key;
        comparisons++;
    }
    return comparisons;
}

// 버블 정렬 함수
int bubbleSort(int arr[], int n) {
    int i, j, swapped, moves = 0;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
                moves += 3; // 각 스왑 시 이동 3회
            }
        }
        if (!swapped)
            break;
    }
    return moves;
}

int main() {
    int arr[SIZE];
    int temp[SIZE];
    int i;

    // 랜덤 데이터 생성
    srand(time(0));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // 선택 정렬
    printf("Selection Sort:\n");
    for (i = 0; i < SIZE; i++) {
        temp[i] = arr[i];
    }
    selectionSort(temp, SIZE);
    printf("Final Result: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n\n");

    // 삽입 정렬 20회 평균 비교 횟수
    printf("Insertion Sort:\n");
    int totalComparisons = 0;
    for (int trial = 0; trial < 20; trial++) {
        for (i = 0; i < SIZE; i++) {
            temp[i] = arr[i];
        }
        totalComparisons += insertionSort(temp, SIZE);
    }
    printf("Average Comparisons: %d\n", totalComparisons / 20);

    printf("Final Result: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n\n");

    // 버블 정렬 20회 평균 이동 횟수
    printf("Bubble Sort:\n");
    int totalMoves = 0;
    for (int trial = 0; trial < 20; trial++) {
        for (i = 0; i < SIZE; i++) {
            temp[i] = arr[i];
        }
        totalMoves += bubbleSort(temp, SIZE);
    }
    printf("Average Moves: %d\n", totalMoves / 20);

    printf("Final Result: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    return 0;
}
