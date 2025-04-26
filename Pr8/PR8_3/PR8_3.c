#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void generateWorstCase(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
}

void generateSortedCase(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void generateRandomCase(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; 
    }
}

int isSorted(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i-1] > arr[i]) {
            return 0;
        }
    }
    return 1;
}

void testCase(const char* name, void (*generator)(int*, int), int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (!arr) {
        printf("Memory allocation error\n");
        return;
    }
    generator(arr, size);

    clock_t start = clock();
    qsort(arr, size, sizeof(int), compare);
    clock_t end = clock();

    if (isSorted(arr, size)) {
        printf("%s: time = %.5f seconds - Sorting is correct\n", name, (double)(end - start) / CLOCKS_PER_SEC);
    } else {
        printf("%s: time = %.5f seconds - sorting error!\n", name, (double)(end - start) / CLOCKS_PER_SEC);
    }
    free(arr);
} 

void findWorstCase(int size, int experiments) {
    int* arr = (int*)malloc(size * sizeof(int));
    double maxTime = 0.0;
    if (!arr) {
        printf("Memory allocation error\n");
        return;
    }

    for (int i = 0; i < experiments; i++) {
        generateRandomCase(arr, size);
        clock_t start = clock();
        qsort(arr, size, sizeof(int), compare);
        clock_t end = clock();

        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        if (elapsed > maxTime) maxTime = elapsed;
    }

    printf("The worst time among %d experiments: %.5f seconds\n", experiments, maxTime);

    free(arr);
}
 


int main() {
    srand(time(NULL));
    int size = 10000; 

    testCase("Worst case scenario", generateWorstCase, size);
    testCase("an already sorted array", generateSortedCase, size);
    testCase("Random array", generateRandomCase, size); 
    findWorstCase(size, 1000);
 

    return 0;
}  
