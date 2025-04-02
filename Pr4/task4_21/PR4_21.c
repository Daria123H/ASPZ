#include <stdio.h>

#include <stdlib.h>

int main() {

    size_t size = 100 * 1024 * 1024; 
    
    char *ptr = malloc(size);
    
    if (ptr == NULL) {
    
        perror("malloc failed");
        
        return 1;
        
    }
    
    printf("Memory allocated successfully\n");
    
    free(ptr);
    
    return 0;
    
}
