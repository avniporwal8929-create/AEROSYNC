#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("====================================\n");
        printf("     AEROSYNC AIR TRAFFIC CONTROL\n");
        printf("====================================\n");
        printf("1. Process Management\n");
        printf("2. IPC Communication\n");
        printf("3. Signal Handling\n");
        printf("4. System Monitoring\n");
        printf("5. View Monitoring Logs\n");
        printf("6. View Flight Report\n");
        printf("7. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\n--- PROCESS MANAGEMENT ---\n");
                system("./aerosync");
                break;

            case 2:
                printf("\n--- IPC COMMUNICATION ---\n");
                system("./aerosync_ipc");
                break;

            case 3:
                printf("\n--- SIGNAL HANDLING ---\n");
                system("./aerosync_signals");
                break;

            case 4:
                printf("\n--- SYSTEM MONITORING ---\n");
                system("bash scripts/monitor.sh");
                break;

            case 5:
                printf("\n--- MONITORING LOGS ---\n");
                system("cat logs/monitor.log");
                break;

            case 6:
                printf("\n--- FLIGHT REPORT ---\n");
                system("cat reports/flight_report.txt");
                break;

            case 7:
                printf("\nAEROSYNC SYSTEM SHUTDOWN!\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}
