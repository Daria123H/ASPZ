#include <stdio.h>

#include <stdlib.h>

int main() {

    size_t huge_size = (size_t)-1; 
    
    void *ptr = malloc(1024);
    
    if (!ptr) {
    
        perror("Initial malloc failed");
        
        return 1;
        
    }
    
    printf("Memory allocated at: %p\n", ptr);
    
    void *new_ptr = realloc(ptr, huge_size);
    
    if (!new_ptr) {
    
        perror("realloc failed");  
        
        free(ptr); 
        
        return 1;
        
    }
    
    printf("Reallocation successful at: %p\n", new_ptr);
    
    free(new_ptr);
    
    return 0;
    
}
