#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>

static void sighandler(int signo) {
    if (signo == SIGINT) {
        int f = open("signalstuff", O_CREAT | O_RDWR | O_APPEND, 0644);
        char mess[64] = "Exit due to SIGINT.";
        write(f, &mess, 64);
        close(f);
        exit(0);
    }
    if (signo == SIGUSR1) {
        printf("Parent process PID: %d\n", getppid());
    }
}

int main() {
    //Signal calls.
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while(1) {
        printf("Current process PID: %d\n", getpid());
        sleep(1);
    }

    return 0;
}
