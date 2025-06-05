#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    fprintf(stderr, "Signal: %d\n", sig);
    signal(sig, SIG_DFL);
    raise(sig);
}

int main() {
    signal(SIGSEGV, handler);
    signal(SIGABRT, handler);
    signal(SIGFPE, handler);
    signal(SIGILL, handler);
    signal(SIGBUS, handler);

    printf("Launch...\n");

    int *p = NULL;
    *p = 1;

    return 0;
}
