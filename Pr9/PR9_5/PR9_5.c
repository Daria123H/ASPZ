#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    FILE *file;
    char *filename = "/tmp/tempfile.txt";
  
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Trouble to creating file");
        return 1;
    }

    fprintf(file, "Temporary file.\n");
    fclose(file);

    printf("Change the owner of a file...\n");
    if (system("sudo chown root:wheel /tmp/tempfile.txt") == -1) {
        perror("Error when changing the owner");
        return 1;
    }
    printf("Change file access rights...\n");
    if (system("sudo chmod 644 /tmp/tempfile.txt") == -1) {
        printf("Error when changing access right");
        return 1;
    }

    printf("Checking access right to file...\n");
    if (access(filename, R_OK) == 0) {
        printf("You have the rights read the file.\n");
    }else{
        printf("You dont have the rights read the file.\n");
    }
  
    if (access(filename, W_OK) == 0) {
        printf("You have the rights record the file.\n");
    } else {
        printf("You dont have the rights record the file.\n");
    }

    return 0;
}
