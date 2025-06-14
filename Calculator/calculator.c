#include <stdio.h>

int main() {
    char op;
    double first, second;

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter two operands: ");
    scanf("%lf %lf", &first, &second);

    switch(op) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf", first, second, first + second);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf", first, second, first - second);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf", first, second, first * second);
            break;
        case '/':
            if(second != 0.0)
                printf("%.2lf / %.2lf = %.2lf", first, second, first / second);
            else
                printf("Error! Division by zero.");
            break;
        default:
            printf("Invalid operator");
    }
    return 0;
}
