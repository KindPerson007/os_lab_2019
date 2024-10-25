#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Ошибка создания дочернего процесса
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Дочерний процесс
        printf("Child process (PID: %d) is sleeping for 2 seconds...\n", getpid());
        sleep(2); // Эмулируем работу дочернего процесса
        printf("Child process (PID: %d) is exiting...\n", getpid());
        exit(0); // Завершение дочернего процесса
    } else {
        // Родительский процесс
        printf("Parent process (PID: %d) is waiting for child to exit...\n", getpid());
        sleep(5); // Даем время дочернему процессу завершиться
        printf("Parent process (PID: %d) is now calling wait().\n", getpid());
        wait(NULL); // Получаем статус завершения дочернего процесса
        printf("Zombie process has been reaped.\n");
    }

    return 0;
}
