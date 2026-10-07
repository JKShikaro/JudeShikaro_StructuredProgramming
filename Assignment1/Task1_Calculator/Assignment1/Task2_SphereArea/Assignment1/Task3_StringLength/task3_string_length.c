#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[100];

    printf("Enter a string (e.g. your name): ");
    scanf(" %99[^\n]", text);

    printf("You entered: %s\n", text);
    printf("Length of the string: %zu\n", strlen(text));

    return 0;
}
