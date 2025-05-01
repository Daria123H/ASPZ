#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void list_files(const char *dir_path) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dir = opendir(dir_path);

    if (dir) {
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
                char path[1024];
                snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
                if (stat(path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode))
                    list_files(path); 
                else
                    printf("%s\n", path);
            }
        }
        closedir(dir);
    }
}

int main() {
    list_files(".");
    return 0;
}
