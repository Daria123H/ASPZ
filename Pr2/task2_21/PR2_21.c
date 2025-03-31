#include <stdio.h>

#include <stdlib.h>

void memory() {

    int *arr = (int *)malloc(10 * sizeof(int));
    
    if (arr == NULL) {
    
        perror("Memory allocation failed");
        
        exit(EXIT_FAILURE);
        
    }
    
    free(arr);  
    
}

int main() {

    memory();
    
    printf("Memory leak example.\n");
    
    return 0;
    
}
