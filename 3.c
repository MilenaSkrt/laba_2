#include <stdio.h>
#include <stdlib.h>

// Структура для хранения данных о товаре
typedef struct {
    char name[100]; // Название товара
    float price;    // Цена товара
} Product;

// Функция для сортировки товаров по цене
void sortProducts(Product *products, int numProducts) {
    int i, j;
    Product temp;

    // Пузырьковая сортировка
    for (i = 0; i < numProducts-1; i++) {
        for (j = 0; j < numProducts-i-1; j++) {
            if (products[j].price > products[j+1].price) {
                // Обмен местами
                temp = products[j];
                products[j] = products[j+1];
                products[j+1] = temp;
            }
        }
    }
}

int main() {
    // Открываем входной файл для чтения
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка при открытии файла\n");
        return 1;
    }

    // Открываем выходной файл для записи
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка при открытии файла\n");
        return 1;
    }

    int numProducts;
    printf("Введите количество товаров: ");
    scanf("%d", &numProducts);

    // Выделяем память для хранения товаров
    Product *products = (Product*) malloc(numProducts * sizeof(Product));

    // Считываем данные о товарах из входного файла
    for (int i = 0; i < numProducts; i++) {
        fscanf(inputFile, "%s%f", products[i].name, &products[i].price);
    }

    // Сортируем товары по цене
    sortProducts(products, numProducts);

    // Выводим отсортированные данные в выходной файл
    for (int i = 0; i < numProducts; i++) {
        fprintf(outputFile, "%s %.2f\n", products[i].name, products[i].price);
    }

    // Освобождаем память
    free(products);

    // Закрываем файлы
    fclose(inputFile);
    fclose(outputFile);

    printf("Данные успешно записаны в файл\n");

    return 0;
}
