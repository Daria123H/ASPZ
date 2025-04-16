#include <stdio.h>

#include <string.h>

int main() {
  
    char buffer[5] = "abcd"; 
  
    int secret = 12345;        

    printf("buffer[5] = %c\n", buffer[5]); 

    buffer[6] = 'X';

    printf("secret після переповнення буфера = %d\n", secret);

    return 0;
}
