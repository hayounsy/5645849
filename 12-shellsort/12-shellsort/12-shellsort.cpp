#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// 쉘 정렬 함수
void shellSort(int arr[], int n, int gap_factor, int* total_comparisons, int* total_moves) {
    int i, j, temp, comparisons = 0, moves = 0;
    int gap = n / gap_factor;

    while (gap > 0) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            moves++; // temp에 값을 넣는 이동
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                comparisons++;
                moves++;
            }
            arr[j] = temp;
            moves++;
        }

        printf("Gap %d - Array: ", gap);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        gap /= gap_factor;
    }

    *total_comparisons = comparisons;
    *total_moves = moves;
}

// 삽입 정렬 함수
void insertionSort(int arr[], int n, int* total_comparisons, int* total_moves) {
    int i, j, key, comparisons = 0, moves = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        moves++; // temp에 값을 넣는 이동
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
            moves++;
        }
        arr[j + 1] = key;
        moves++;
    }

    *total_comparisons = comparisons;
    *total_moves = moves;
}

int main() {
    int arr[SIZE], temp[SIZE];
    int i;
    int comparisons, moves;
    int total_comparisons_shell = 0, total_moves_shell = 0;
    int total_comparisons_insert = 0, total_moves_insert = 0;

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

    // 쉘 정렬 (Gap N/2)
    printf("Shell Sort (Gap N/2):\n");
    for (i = 0; i < SIZE; i++) {
        temp[i] = arr[i];
    }
    shellSort(temp, SIZE, 2, &comparisons, &moves);
    total_comparisons_shell += comparisons;
    total_moves_shell += moves;

    printf("Final Array (Gap N/2): ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    printf("Average Comparisons: %d\n", total_comparisons_shell);
    printf("Average Moves: %d\n\n", total_moves_shell);

    // 쉘 정렬 (Gap N/3)
    printf("Shell Sort (Gap N/3):\n");
    for (i = 0; i < SIZE; i++) {
        temp[i] = arr[i];
    }
    shellSort(temp, SIZE, 3, &comparisons, &moves);
    total_comparisons_shell += comparisons;
    total_moves_shell += moves;

    printf("Final Array (Gap N/3): ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    printf("Average Comparisons: %d\n", total_comparisons_shell);
    printf("Average Moves: %d\n\n", total_moves_shell);

    // 삽입 정렬
    printf("Insertion Sort:\n");
    for (i = 0; i < SIZE; i++) {
        temp[i] = arr[i];
    }
    insertionSort(temp, SIZE, &total_comparisons_insert, &total_moves_insert);

    printf("Final Array (Insertion): ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    printf("Total Comparisons: %d\n", total_comparisons_insert);
    printf("Total Moves: %d\n\n", total_moves_insert);

    // 비교 결과
    printf("Comparison between Shell Sort and Insertion Sort:\n");
    printf("Shell Sort Comparisons (Average): %d\n", total_comparisons_shell / 2);
    printf("Shell Sort Moves (Average): %d\n", total_moves_shell / 2);
    printf("Insertion Sort Comparisons: %d\n", total_comparisons_insert);
    printf("Insertion Sort Moves: %d\n", total_moves_insert);

    return 0;
}
