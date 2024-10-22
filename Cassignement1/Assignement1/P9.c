#include <stdio.h>

int main() {
    float num1, num2, result;
    char operation;

    
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    
    switch (operation) {
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
            if (num2 != 0) {  
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;

        default:
            printf("Invalid operation!\n");
            break;
    }

    return 0;
}