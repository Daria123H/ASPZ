#include <time.h>
#include <unistd.h>
#include <signal.h>

void h(int s){
    time_t t = time(NULL);
    char b[9];
    write(1, "\r", 1);
    size_t len = strftime(b, sizeof b, "%H:%M:%S", localtime(&t));
    write(1, b, len);
    alarm(1);
}

int main(){
    signal(SIGALRM,h);
    alarm(1);
    while(1) pause();
}
