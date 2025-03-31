#include <stdio.h>

#include <stdlib.h>

int global_var = 42;   

int var;

void function() {} 

int main() {

    int local_var = 10; 
    
    static int static_var = 20;
    
    int *heap_var = malloc(sizeof(int)); 
    
    printf("Text segment: %p\n", (void*)&function);
    
    printf("Data segment (initialized): %p\n", (void*)&global_var);
    
    printf("BSS segment (uninitialized): %p\n", (void*)&var);
    
    printf("Data segment (static): %p\n", (void*)&static_var);
    
    printf("Heap: %p\n", (void*)heap_var);
    
    printf("Stack: %p\n", (void*)&local_var);
    
    free(heap_var);
    
    return 0;
    
}
