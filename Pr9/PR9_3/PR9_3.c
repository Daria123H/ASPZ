#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("/home/dasha/PR9_3.txt", "w");
    if (file == NULL) {
        perror("Unable to create a file");
        return 1;
    }
    fprintf(file, "Text for file\n");
    fclose(file);

    printf("Now copy the file using root...\n");
    system("sudo cp /home/dasha/PR9_3.txt /home/dasha/PR9_3copy.txt");

    printf("Now let's try to modify the file...\n");
    system("sudo vi /home/dasha/PR9_3copy.txt"); 

    printf("Now let's try to delete the file...\n");
    system("sudo rm /home/dasha/PR9_3copy.txt");

    return 0;
}
