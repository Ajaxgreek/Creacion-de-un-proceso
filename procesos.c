#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        // Error al crear el proceso
        perror("Error al crear el proceso");
        return 1;
    }

    if (pid == 0) {
        // PROCESO HIJO
        printf("\nProceso hijo (PID: %d)\n", getpid());

        for (int i = 10000; i >= 1; i--) {
            printf("%d ", i);
            fflush(stdout);
        }

        printf("\n");
    } 
    else {
        // PROCESO PADRE
        printf("\nProceso padre (PID: %d)\n", getpid());

        for (int i = 1; i <= 10000; i++) {
            printf("%d ", i);
            fflush(stdout);
        }

        printf("\n");

        // Esperar a que termine el hijo
        wait(NULL);
    }

    return 0;
}