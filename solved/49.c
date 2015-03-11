#include <stdio.h>
#include "primes.c"

int is_permutation(long first, long second, int length) {
    /* assumes strings are the same length */

    int firstDigits[10] = {0};
    int secondDigits[10] = {0};
    int c;

    for(c = 0; c < length; c++) {
        firstDigits[first % 10]++;
        secondDigits[second % 10]++;
        first /= 10;
        second /= 10;
    }

    for(c = 0; c < 10; c++)
        if(firstDigits[c] != secondDigits[c])
            return 0;
    return 1;
}

int main() {

    int numCap = 10000;
    long primes[numCap];
    int numPrimes = get_primes(numCap, 0, primes);

    long *p = primes;
    long i;
    while((++p - primes) < numPrimes && *p < numCap) {

        if(*p < 1488) continue;

        for(i = 2; i < 3400 && (*p + (i * 2)) < numCap; i += 2) {

            if(test_prime(*p + i, primes, numCap) &&
                test_prime(*p + (i * 2), primes, numCap) &&
                is_permutation(*p, *p + i, 4) &&
                is_permutation(*p, *p + (i * 2), 4))
            {
                printf("%ld%ld%ld\n", *p, *p + i, *p + (i * 2));
            }
        }
    }

    return 0;
}