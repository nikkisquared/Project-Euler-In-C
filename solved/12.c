#include <stdio.h>
#include <math.h>

/* to compile: gcc 12.c -o 12 -lm */

int main() {

    long triNum = 0;
    long nextStep = 1;

    int divisors;
    long num;

    do {
        triNum += nextStep++;
        // every number >1 is divisible by 1 and itself
        divisors = 2;
        num = 1;

        while(num++ < sqrt(triNum) - 1) {
            if(triNum % num == 0) {
                divisors += 2;
            }
        }

    } while(divisors < 500);

    printf("%ld has %d divisors!\n", triNum, divisors);
}