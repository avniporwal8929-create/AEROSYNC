
#include "atc.h"
#include <errno.h>

volatile sig_atomic_t interrupted = 0;
volatile sig_atomic_t child_changed = 0;

void handle_sigint(int sig) {
    (void)sig;
    interrupted = 1;
}
void handle_sigchld(int sig) {
    (void)sig;
    child_changed = 1;
}
char *aircraft[TOTAL_AIRCRAFT] = {
    "AI101",
    "BA207",
    "SQ412"
};

int main() {

    pid_t pids[TOTAL_AIRCRAFT];
    int reaped[TOTAL_AIRCRAFT] = {0};
    int created = 0;

    struct sigaction sa_int;
    struct sigaction sa_chld;

    sa_int.sa_handler = handle_sigint;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;

    sigaction(SIGINT, &sa_int, NULL);

    sa_chld.sa_handler = handle_sigchld;
    sigemptyset(&sa_chld.sa_mask);
    sa_chld.sa_flags = 0;

    sigaction(SIGCHLD, &sa_chld, NULL);

    printf("\n===== AEROSYNC SIGNAL HANDLING =====\n");

    printf("ATC Controller PID: %d\n", getpid());

    for (int i = 0; i < TOTAL_AIRCRAFT; i++) {

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            break;
        }

        if (pid == 0) {

            signal(SIGINT, SIG_IGN);

            printf("\nAircraft %s started. PID: %d\n",
                   aircraft[i], getpid());

            printf("Aircraft %s is flying...\n", aircraft[i]);

            for (int j = 0; j < 10; j++) {
                sleep(1);
            }

            printf("Aircraft %s completed its flight.\n",
                   aircraft[i]);

            exit(0);
        }

        pids[created] = pid;
        created++;
    }

    printf("\nATC is monitoring all aircraft.\n");

    printf("Press Ctrl+C to simulate an emergency.\n");

    for (int i = 0; i < created; i++) {

        int status;
        pid_t result;

        do {
            result = waitpid(pids[i], &status, 0);
        } while (result == -1 &&
                 errno == EINTR && !interrupted);

        if (result == pids[i]) {
            reaped[i] = 1;
        }

        if (interrupted) {
            break;
        }
    }

    if (interrupted) {

        printf("\nEMERGENCY! SIGINT received by ATC.\n");

        printf("Sending SIGTERM to active aircraft...\n");

        for (int i = 0; i < created; i++) {
            if (!reaped[i]) {
                kill(pids[i], SIGTERM);
            }
        }

        for (int i = 0; i < created; i++) {

            if (!reaped[i]) {

                while (waitpid(pids[i], NULL, 0) == -1) {
                    if (errno == EINTR)
                        continue;
                    break;
                }

                reaped[i] = 1;
            }
        }

        printf("Emergency shutdown completed.\n");
    }

    if (child_changed) {
        printf("\nATC received SIGCHLD notification.\n");
    }

    printf("\nAll aircraft processes handled.\n");

    printf("ATC Controller shutting down.\n");

    return 0;
}
