
#include "atc.h"
#include <errno.h>
#include <string.h>

typedef struct {
    char aircraft[16];
    char status[32];
    pid_t pid;
} FlightMessage;

int write_full(int fd, const void *buffer, size_t size) {

    const char *ptr = buffer;
    size_t total = 0;

    while (total < size) {

        ssize_t n = write(fd, ptr + total, size - total);

        if (n < 0) {
            if (errno == EINTR)
                continue;

            return -1;
        }

        if (n == 0)
            return -1;

        total += n;
    }

    return 0;
}

int read_full(int fd, void *buffer, size_t size) {

    char *ptr = buffer;
    size_t total = 0;

    while (total < size) {

        ssize_t n = read(fd, ptr + total, size - total);

        if (n == 0)
            return total == 0 ? 0 : -1;

        if (n < 0) {
            if (errno == EINTR)
                continue;

            return -1;
        }

        total += n;
    }

    return 1;
}
char *aircraft[TOTAL_AIRCRAFT] = {
    "AI101",
    "BA207",
    "SQ412"
};

int main() {

    int fd[2];

    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    printf("\n===== AEROSYNC IPC SYSTEM =====\n");

    printf("ATC Controller PID: %d\n", getpid());

    int created = 0;

    for (int i = 0; i < TOTAL_AIRCRAFT; i++) {

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            break;
        }

        if (pid == 0) {

            close(fd[0]);

            FlightMessage message;

            snprintf(message.aircraft,
                     sizeof(message.aircraft),
                     "%s", aircraft[i]);

            message.pid = getpid();

            strcpy(message.status, "Flight Started");

            write_full(fd[1], &message, sizeof(message));

            sleep(3);

            strcpy(message.status, "Flight Completed");

            write_full(fd[1], &message, sizeof(message));

            close(fd[1]);

            exit(0);
        }

        created++;
    }

    close(fd[1]);

    FlightMessage message;

    while (1) {

        int result = read_full(fd[0], &message,
                               sizeof(message));

        if (result == 0)
            break;

        if (result == -1) {
            perror("Pipe reading failed");
            break;
        }

        printf("\nATC RECEIVED MESSAGE\n");

        printf("Aircraft: %s\n", message.aircraft);

        printf("Aircraft PID: %d\n", message.pid);

        printf("Status: %s\n", message.status);
    }

    close(fd[0]);

    for (int i = 0; i < created; i++) {
        wait(NULL);
    }

    printf("\nAll aircraft reports received.\n");

    printf("ATC Controller shutting down.\n");

    return 0;
}
