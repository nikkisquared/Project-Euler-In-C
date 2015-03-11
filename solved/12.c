#include <stdio.h>
#include <math.h>

/* to compile: gcc 12.c -o 12.o -lm */

int main() {

    long triNum = 0;
    long nextStep = 1;
    int divisors = 0;
    long n;

    while(divisors < 500) {

        // every number >1 is divisible by 1 and itself
        // so divisors and n can start at 2
        divisors = 2;
        n = 2;
        triNum += nextStep++;

        while(n < sqrt(triNum)) {
            if(triNum % n == 0)
                divisors += 2;
            n++;
        }
    }

    printf("%ld\n", triNum);

    return 0;
}