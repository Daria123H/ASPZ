#include <stdlib.h>
int main() {
    int *arr = malloc(sizeof(int) * 1000);
    arr[1000] = 1; 
    free(arr);
    return 0;
}

