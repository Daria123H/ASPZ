#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int dirs = 0, depth_sum = 0, max_depth = 0;

void walk(const char *path, int depth) {
    DIR *d = opendir(path);
    if (!d) return;
    struct dirent *e;
    while ((e = readdir(d))) {
        if (e->d_name[0] == '.') continue;
        char buf[1024];
        snprintf(buf, sizeof(buf), "%s/%s", path, e->d_name);
        struct stat st;
        if (!stat(buf, &st) && S_ISDIR(st.st_mode)) {
            dirs++; depth_sum += depth + 1;
            if (depth + 1 > max_depth) max_depth = depth + 1;
            walk(buf, depth + 1);
        }
    }
    closedir(d);
}

int main(int c, char **v) {
    if (c < 2) return printf("Використання: %s <шлях>\n", v[0]), 1;
    walk(v[1], 0);
    printf("Директорій: %d\nМакс. глибина: %d\nСер. глибина: %.2f\n",
           dirs, max_depth, dirs ? (double)depth_sum / dirs : 0);
    return 0;
}
