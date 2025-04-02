#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>

#include <errno.h>

int main () {
  
	int xa = 1000000;
  
	int xb = 1000000;
  
	int num = xa * xb;
  
	printf ("Multiplication result: %d\n", num);
  
}

void *ptr = malloc(num);

if (ptr){
  
	printf("Memory allocated: %d bytes\n", num);
  
	free(ptr);
  
} else {
  
perror ("malloc failed");
  
}

return 0;

}  
