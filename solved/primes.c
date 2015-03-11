#include <stdio.h>
#include <math.h>

/* GENERAL USAGE:

#include "primes.c"

    long primes[get_primes_cap()];
    long numCap = 1000000;
    long primesWanted = 500000;
    int numPrimes = get_primes(numCap, primesWanted, primes);
*/

/* to compile: gcc [file].c -o [file] -lm */

// upper limits to prevent seg faults
#define PRIMESCAP 1000000
#define NUMCAP 15485864

long get_primes_cap() {
    return PRIMESCAP;
}

int test_prime(long number, long primes[], long primesCap) {

    long *primeIndex = primes;
    int isPrime = 1;

    while(isPrime && (++primeIndex - primes) < primesCap &&
            *primeIndex && *primeIndex <= sqrt(number))
    {
        isPrime = (number % *primeIndex != 0);
    }

    return (isPrime) ? number : 0;
}

int get_primes(long numCap, long primesCap, long primes[]) {
    /* assumes primes is empty and initialized properly */

    if(!primesCap || primesCap > PRIMESCAP) primesCap = PRIMESCAP;
    if(!numCap || numCap > NUMCAP) numCap = NUMCAP;

    primes[0] = 2;
    int numPrimes = 1;

    long number = 3;
    long result;

    while(numPrimes < primesCap && number < numCap) {

        result = test_prime(number, primes, primesCap);
        if(result) {
            primes[numPrimes++] = number;
        }
        number += 2;
    }

    return numPrimes;
}