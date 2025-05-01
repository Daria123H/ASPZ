#include <stdio.h>
#include <time.h>

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);  
    
    // Ваш код
    for (int i = 0; i < 1000000; i++);
    
    clock_gettime(CLOCK_MONOTONIC, &end);  
    
    double elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
    printf("Time done: %.3f мс\n", elapsed);
    
    return 0;
}
