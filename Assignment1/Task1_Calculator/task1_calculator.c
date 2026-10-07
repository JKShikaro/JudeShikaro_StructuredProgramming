#include <stdio.h>

int main(void) {
    char operator;
    double num1, num2, result;

    //Get the operation from the user
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    //Get the two numbers
    printf("Enter two numbers separated by a space: ");
    scanf("%lf %lf", &num1, &num2);

    //Process the math logic
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero!\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
    }

    return 0;
}
