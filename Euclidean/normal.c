#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y){

    if(y == 0)
    {
        return x;
    } else if(x == 0) {
        return y;
    }

    if(x > y) {

        x %= y;
        gcd(y, x);

    } else if (y > x) {
        
        y %= x;
        gcd(x, y);
    }

}

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Invalid input: Usage %d <number1> <number2>\n", argv[0]);
    } else {
        int a = strtol(argv[1], NULL, 10), b = strtol(argv[2], NULL, 10);
        printf("GCD(%d,%d) = %d\n", a, b, gcd(a,b));
    }
    return 0;
}