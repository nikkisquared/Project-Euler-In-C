#include <stdio.h>
#include <math.h>
#include "primes.c"

#define HUGENUM 600851475143

/* to compile: gcc 3.c -o 3.o -lm */

int main()
{
    long primes[99999] = {0};
    int numPrimes = get_primes(sqrt(HUGENUM), 0, primes);

    int p;
    long highest = 0;
    for(p = 0; p < numPrimes; p++) {
        if(HUGENUM % primes[p] == 0) {
            highest = primes[p];
        }
    }

    printf("%ld\n", highest);

    return 0;
}