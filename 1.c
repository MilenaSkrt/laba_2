#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Размер массива

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int arr[SIZE];

    srand(time(NULL)); // Инициализация генератора псевдослучайных чисел

    // Заполнение массива псевдослучайными числами
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100; // Генерация числа от 0 до 99
    }

    printf("Массив в прямом порядке:\n");
    printArray(arr, SIZE);

    // Открытие файла для записи
    FILE *file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("Ошибка при открытии файла!\n");
        return 1;
    }

    // Запись массива в обратном порядке в файл
    reverseArray(arr, SIZE);
    for (int i = 0; i < SIZE; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    // Закрытие файла
    fclose(file);

    printf("Массив записан в файл 'output.txt' в обратном порядке.\n");

    return 0;
}


