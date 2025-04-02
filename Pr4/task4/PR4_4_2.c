#include <stdio.h>

#include <stdlib.h>

int main() {
  
    void *ptr = NULL;

    for (int i = 0; i < 2; ++i) {
      
        if (!ptr) {
          
            ptr = malloc(10);  
          
            if (!ptr) {
              
                perror("malloc failed");
              
                return 1; 
              
            }
          
            printf("Memory allocated\n");
          
        }

        if (ptr) {
          
            printf("Using ptr in iteration %d\n", i + 1);
          
        }
      
        if (i == 1) {
          
            free(ptr);
          
            printf("Memory freed\n");
          
        }
      
    }

    return 0;
  
}
