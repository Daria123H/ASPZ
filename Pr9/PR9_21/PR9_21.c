#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Failed to create the file");
        return 1;
    }
    
    fprintf(file, "This is a test file to demonstrate hard links.\n");
    
    fclose(file);

    if (link("example.txt", "example_link.txt") != 0) {
        perror("Failed to create the hard link");
        return 1;
    }
  
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Failed to open the file");
        return 1;
    }

    if (remove("example.txt") != 0) {
        perror("Failed to remove the file");
        return 1;
    }
  
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Read from the file: %s", buffer);
    }

    fclose(file);

    return 0;
}
