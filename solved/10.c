#include <stdio.h>
#include "primes.c"

#define HUGENUM 2000000

/* to compile: gcc 10.c -o 10.o -lm */

int main() {

    long primes[get_primes_cap()];
    int numPrimes = get_primes(HUGENUM, 0, primes);
    long long sum = 0;
    int i;

    for(i = 0; i < numPrimes; i++) {
        sum += primes[i];
    }

    printf("%lld\n", sum);

    return 0;
}