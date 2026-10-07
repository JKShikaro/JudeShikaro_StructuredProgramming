#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define DELAY_ONE_SECOND() Sleep(1000)
#else
#include <unistd.h>
#define DELAY_ONE_SECOND() sleep(1)
#endif

#define MAX_ATTEMPTS 3
#define PIN_LENGTH 4
#define LOCKOUT_SECONDS 5

int main(void)
{
    const char correctPin[PIN_LENGTH + 1] = "1234";
    char enteredPin[64];
    int attempts = 0;
    int authenticated = 0;
    int choice = 0;

    printf("=== PIN-Based Door Lock System ===\n");

    /* Keep asking until the user gets in */
    while (!authenticated)
    {
        printf("\nEnter your 4-digit PIN: ");
        if (scanf("%63s", enteredPin) != 1)
        {
            printf("Input error. Exiting.\n");
            return 1;
        }

        size_t len = strlen(enteredPin);

        /* Validate PIN length */
        if (len < PIN_LENGTH)
        {
            printf("PIN is too short (must be 4 digits)\n");
        }
        else if (len > PIN_LENGTH)
        {
            printf("PIN is too long (must be 4 digits)\n");
        }
        else
        {
            printf("PIN is exactly 4 digits\n");
        }

        /* Check the PIN itself (a wrong-length PIN can never match) */
        if (strcmp(enteredPin, correctPin) == 0)
        {
            authenticated = 1;
            printf("Correct PIN. Access granted!\n");
        }
        else
        {
            attempts++;
            int remaining = MAX_ATTEMPTS - attempts;
            printf("Incorrect PIN.\n");

            if (remaining > 0)
            {
                printf("Remaining attempts: %d\n", remaining);
            }
            else
            {
                printf("System locked! Wait for %d seconds...\n", LOCKOUT_SECONDS);

                for (int i = LOCKOUT_SECONDS; i >= 1; i--)
                {
                    printf("%d... ", i);
                    fflush(stdout);
                    DELAY_ONE_SECOND();
                }

                printf("\nYou can try again now.\n");
                attempts = 0; /* reset attempts after lockout */
            }
        }
    }

    /* Menu loop */
    do
    {
        printf("\n=== Device Menu ===\n");
        printf("1. Open Door\n");
        printf("2. Change Username\n");
        printf("3. Change PIN\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
        {
            /* Non-numeric input: clear the buffer and treat as invalid */
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            choice = 0;
        }

        switch (choice)
        {
        case 1:
            printf("Access granted. Door unlocked\n");
            break;
        case 2:
            printf("Change username feature coming soon.\n");
            break;
        case 3:
            printf("Change PIN feature coming soon.\n");
            break;
        case 4:
            printf("Exiting system.\n");
            break;
        default:
            printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
