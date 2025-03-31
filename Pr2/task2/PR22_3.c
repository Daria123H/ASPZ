#include <stdio.h>

void testFunction() {

    int localArray[1000]; 
    
    static int staticArray[1000]; 
    
    static int Array[1000] = {1}; 
    
    printf("Testing function...\n");
    
}

int main() {

    testFunction();
    
    printf("Hello, World!\n");
    
    return 0;
    
}
