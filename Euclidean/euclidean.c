#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#define EXIT_ERROR 1

void gcd(mpz_t gcd_result, mpz_t a, mpz_t b) {

    /*mpz numbers are not integers but structs.
      They cannot be returned directly. You need
      to have a third variable 'gcd_result' which 
      holds the GCD.Just print that from this void 
      function.*/
    mpz_t c; 
    mpz_init(c);
    
    if(mpz_cmp_ui(b, 0) == 0) { // this function gives < 0, if arg1 < arg2; gives 0, if arg1 == arg2; gives > 0, if arg1 > arg2
        //basically checks if b == 0, return a.
        mpz_set(gcd_result, a);
        return;
    } 

        mpz_mod(c, a, b);
        gcd(gcd_result, b, c);

}

int main(int argc, char *argv[]){
    
    if(argc < 3){
        printf("Invalid input given. Usage %s <number1> <number2>\n", argv[0]);
        return EXIT_ERROR;
    } else {
        mpz_t a, b, gcd_result;
        
        mpz_init(a);
        mpz_init(b);
        mpz_init(gcd_result);

        if(mpz_set_str(a, argv[1], 10) != 0 || mpz_set_str(b, argv[2], 10) != 0)
        {
            fprintf(stderr, "Error: Invalid number format.\n");
        }

        gcd(gcd_result, a, b);
        gmp_printf("GCD(%Zd, %Zd) = %Zd\n", a, b, gcd_result);
    }

    return 0;
}
