#include <stdlib.h>
int main() {
    int *p = malloc(4);
    free(p);
    *p = 42; 
    return 0;
}

