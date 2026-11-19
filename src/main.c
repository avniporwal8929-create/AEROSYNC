
#include "atc.h"

char *aircraft[TOTAL_AIRCRAFT] = {
    "AI101",
    "BA207",
    "SQ412"
};

int main() {

    printf("===== AEROSYNC AIR TRAFFIC CONTROL =====\n");

    printf("ATC Controller PID: %d\n", getpid());

    int created = 0;

    for (int i = 0; i < TOTAL_AIRCRAFT; i++) {

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            break;
        }

        if (pid == 0) {

            printf("\nAircraft %s started\n", aircraft[i]);

            printf("Aircraft PID: %d\n", getpid());

            printf("Aircraft %s is flying...\n", aircraft[i]);

            sleep(3);

            printf("Aircraft %s completed flight\n", aircraft[i]);

            exit(0);
        }

        created++;
    }

    for (int i = 0; i < created; i++) {
        wait(NULL);
    }

    printf("\nAll aircraft have completed their flights.\n");

    printf("ATC Controller shutting down.\n");

    return 0;
}

