#include "primes.c"

/* to compile: gcc 27.c -o 27 -lm */

#define PRIMESWANTED 1000

int main() {

    long primes[PRIMESWANTED];
    int numPrimes = get_primes(0, PRIMESWANTED, primes);

    int a, b, n, nCap, curPrimes;
    int maxPrimes = 0;
    long formula, product;

    for(a = -999; a < 1000; a++) {
        for(b = -999; b < 1000; b++) {

            n = 0;
            curPrimes = 0;
            nCap = (abs(a) < abs(b)) ? abs(a) : abs(b);

            do {
                n++;
                curPrimes++;
                formula = pow(n, 2) + a * n + b;
            } while(n <= nCap && test_prime(formula, primes, PRIMESWANTED));

            if(curPrimes > maxPrimes) {
                product = a * b;
                //printf("%d | %d\n", a, b);
            }
        }
    }

    printf("%ld\n", product);

    return 0;
}