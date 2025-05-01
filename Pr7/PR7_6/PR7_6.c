#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct dirent *e;
    DIR *d = opendir(".");
    char *list[512];
    int n = 0;
    struct stat s;

    while ((e = readdir(d)))
        if (stat(e->d_name, &s) == 0 && S_ISDIR(s.st_mode) &&
            strcmp(e->d_name, ".") && strcmp(e->d_name, ".."))
            list[n++] = strdup(e->d_name);

    closedir(d);
    qsort(list, n, sizeof(char*), (int(*)(const void*, const void*))strcmp);

    for (int i = 0; i < n; i++) {
        puts(list[i]);
        free(list[i]);
    }

    return 0;
}
