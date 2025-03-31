#include <stdio.h>

#include <time.h>

#include <limits.h>

int main() {

    time_t max_time = (time_t) ~0; 
    
    if (max_time < 0) {
    
        max_time = max_time >> 1; 
        
    }
    
    printf("Максимальне значення time_t: %ld\n", (long) max_time);
    
    printf("Дата та час, коли time_t закінчиться: %s", ctime(&max_time));
    
    return 0;
    
} 
