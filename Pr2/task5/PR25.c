#include <stdio.h> 

#include <stdint.h>

#include <stdlib.h>


void print_stack() {

    uintptr_t sp;
    
    asm volatile ("movq %%rsp, %0" : "=r"(sp)); 
    
    printf("Stack pointer (RSP): %p\n", (void*)sp);
    
}

void function_c() {

    printf("Inside function_c\n");
    
    print_stack(); 
    
}

void function_b() {

    printf("Inside function_b\n");
    
    print_stack();
    
    function_c();
    
}


void function_a() {

    printf("Inside function_a\n");
    
    print_stack();
    
    function_b();
    
}


int main() {

    printf("Inside main\n");
    
    print_stack();
    
    function_a();
    
    return 0;
    
} 
