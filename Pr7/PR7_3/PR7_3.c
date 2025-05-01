#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s PR7_3 Second\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open a file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, argv[2]) != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);
    return 0;
}
