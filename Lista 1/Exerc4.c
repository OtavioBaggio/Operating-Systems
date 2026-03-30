#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t f1, f2, f3, f4, f5;

    // Filho 1
    f1 = fork();

    if (f1 == 0) {
        printf("Filho 1 - PID: %d, Pai: %d\n", getpid(), getppid());

        // Filho 2
        f2 = fork();
        if (f2 == 0) {
            printf("Filho 2 - PID: %d, Pai: %d\n", getpid(), getppid());
        } else {
            // Filho 3
            f3 = fork();
            if (f3 == 0) {
                printf("Filho 3 - PID: %d, Pai: %d\n", getpid(), getppid());
            }
        }
    } else {
        // Filho 4
        f4 = fork();

        if (f4 == 0) {
            printf("Filho 4 - PID: %d, Pai: %d\n", getpid(), getppid());

            // Filho 5
            f5 = fork();
            if (f5 == 0) {
                printf("Filho 5 - PID: %d, Pai: %d\n", getpid(), getppid());
            }
        }
    }

    return 0;
}
