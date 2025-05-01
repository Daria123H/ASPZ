#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void perms(mode_t m) {
    char t = S_ISDIR(m) ? 'd' : S_ISLNK(m) ? 'l' : '-';
    printf("%c%c%c%c%c%c%c%c%c%c ", t,
        m & S_IRUSR ? 'r' : '-', m & S_IWUSR ? 'w' : '-', m & S_IXUSR ? 'x' : '-',
        m & S_IRGRP ? 'r' : '-', m & S_IWGRP ? 'w' : '-', m & S_IXGRP ? 'x' : '-',
        m & S_IROTH ? 'r' : '-', m & S_IWOTH ? 'w' : '-', m & S_IXOTH ? 'x' : '-');
}

int main() {
    DIR *d = opendir(".");
    struct dirent *e;
    char t[64];

    while ((e = readdir(d))) {
        struct stat s;
        if (e->d_name[0] == '.') continue; =
        stat(e->d_name, &s);
        perms(s.st_mode);
        printf("%lu ", s.st_nlink);
        printf("%s %s ", getpwuid(s.st_uid)->pw_name, getgrgid(s.st_gid)->gr_name);
        printf("%lld ", (long long)s.st_size);
        strftime(t, sizeof(t), "%b %d %H:%M", localtime(&s.st_mtime));
        printf("%s %s\n", t, e->d_name);
    }
    closedir(d);
    return 0;
}
