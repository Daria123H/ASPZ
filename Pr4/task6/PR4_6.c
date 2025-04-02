#include <stdio.h>

#include <stdlib.h>

int main() {

    void *ptr = NULL;
    
    ptr = realloc(NULL, 100);
    
    if (ptr) {
    
        printf("realloc(NULL, 100) успішно, ptr = %p\n", ptr);
        
    } else {
    
        printf("realloc(NULL, 100) повернув NULL\n");
        
    }
    
    void *new_ptr = realloc(ptr, 0);
    
    if (new_ptr) {
    
        printf("realloc(ptr, 0) повернув %p\n", new_ptr);
        
    } else {
    
        printf("realloc(ptr, 0) повернув NULL (звільнено пам'ять)\n");
        
    }
    
    return 0;
    
}
