#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* randomArr(int len){
    double* arr = (double*)malloc(len * sizeof(double)); 

    for(int i = 0; i < len; i++){
        // arr[i] = (double)rand();
        arr[i] = (double)rand() / RAND_MAX;
    }

    return arr;
}

void outputArr(double arr[], int len){
    for(int i = 0; i < len; i++){
        printf("%f", arr[i]);
        printf("\n");
    }
    printf("\n");
}

int compar(const void *a, const void *b){
    double double_a = *((double*)a);
    double double_b = *((double*)b);

    if (double_a == double_b) return 0;
    else if (double_a < double_b) return -1;
    else return 1;
}

int main(int argc, char const *argv[])
{
    int arrlen;
    printf("Input length of array: ");
    scanf("%d", &arrlen);

    if (arrlen <=0)
    {
        printf("Error of length of array");
        return 1;
    }

    double* arr = randomArr(arrlen);
    printf("Made array\n");
    outputArr(arr, arrlen);
    //all good

    qsort(arr, arrlen, sizeof(double), compar);

    FILE *file;
    file = fopen (argv[1], "w");

    if(file == NULL){
        printf("ERROR of inputing file");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < arrlen; i++){
        fprintf(file, "%f\n", arr[i]);
    }

    fclose(file);
    free(arr);

    return 0;
}
