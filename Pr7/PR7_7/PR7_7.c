#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    DIR *d = opendir("."); 
    struct dirent *f; 
    struct stat s; 
    char c;
    if (!d) { perror("opendir"); return 1; }

    while ((f = readdir(d))) {
        if (!stat(f->d_name, &s) && S_ISREG(s.st_mode) && (s.st_mode & S_IXUSR)) {
            printf("%s — grant reading permission to others? (y/n): ", f->d_name);
            scanf(" %c", &c);
            if (c == 'y' || c == 'Y') {
                if (chmod(f->d_name, s.st_mode | S_IROTH) != 0)
                    perror("chmod");
            }
        }
    }
    closedir(d);
    return 0;
}
