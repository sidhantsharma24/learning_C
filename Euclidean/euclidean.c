#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#define EXIT_ERROR 1

void gcd(const mpz_t result, mpz_t a, mpz_t b) {

    mpz_t c;
    mpz_init(c);
    if(mpz_cmp(a,b) > 0) {
        mpz_mod(c, a, b); // c = a % b;

    }
    gmp_printf("%Zd", c);
}
int main(int argc, char *argv[]){
    
    if(argc < 3){
        printf("Invalid input given. Usage %d <number1> <number2>\n", argv[0]);
        return EXIT_ERROR;
    } else {
        mpz_t a, b, result;
        
        mpz_init(a);
        mpz_init(b);
        mpz_init(result);

        if(mpz_set_str(a, argv[1], 10) != 0 || mpz_set_str(b, argv[2], 10) != 0)
        {
            fprintf(stderr, "Error: Invalid number format.\n");
        }

        gcd(result, a, b);
    }

    return 0;
}
