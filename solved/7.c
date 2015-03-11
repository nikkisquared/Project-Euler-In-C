#include <stdio.h>
#include "primes.c"

/* to compile: gcc 7.c -o 7 -lm */

int main()
{ 
    int primesToFind = 10001;
    long primes[primesToFind];
    int numPrimes = get_primes(0, primesToFind, primes);

    printf("%ld\n", primes[primesToFind - 1]);

    return 0;
}