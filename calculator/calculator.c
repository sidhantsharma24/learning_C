#include "include/calculator.h"
#include <stdio.h>
#include <stdint.h>

int main()
{
    printf("Welcome to the world's most advanced and secure calculator! Totally not vulnerable to buffer overflow !\n");
    printf("Choose an operation.\n");
    printf(" 0. Divide\n 1. Multiply\n 2. Add\n 3. Subtract\n 4. Modulo\n 5. Exit\n");
    int choice = -1;
    // printf("Enter option: ");
    // scanf("%d", &choice);

    uint64_t x,y=0;
    do {

        printf("Enter option: ");
        scanf("%d", &choice);
        
        switch (choice) {

            case 0:
                printf("Enter first number: ");
                scanf("%ld", &x);
                printf("Enter second number: ");
                scanf("%ld", &y);
                uint64_t quotient = divide(x,y);
                printf("%ld/%ld = %ld, remainder = %ld\n", x, y, quotient, mod(x,y));
                break;

            case 1:
                printf("Enter first number: ");
                scanf("%ld", &x);
                printf("Enter second number: ");
                scanf("%ld", &y); 
                uint64_t product = multiply(x,y);
                printf("%ld * %ld = %ld\n", x, y, product);
                break;

            case 2:
                printf("Enter first number: ");
                scanf("%ld", &x);
                printf("Enter second number: ");
                scanf("%ld", &y);
                uint64_t sum = add(x,y);
                printf("%ld + %ld = %ld\n", x,y,sum);
                break;

            case 3:
                printf("Enter first number: ");
                scanf("%ld", &x);
                printf("Enter second number: ");
                scanf("%ld", &y);
                uint64_t difference = subtract(x,y);
                printf("%ld - %ld = %ld\n", x, y, difference);
                break;

            case 4:
                printf("Enter first number: ");
                scanf("%ld", &x);
                printf("Enter second number: ");
                scanf("%ld", &y);
                uint64_t modulo = mod(x,y);
                printf("%ld mod %ld = %ld\n", x, y, modulo);
                break;

            case 5:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice.\n");
                break;

        }

    }while(choice != 5);
    
    return 0;
}

