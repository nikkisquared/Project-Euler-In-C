#include <stdio.h>
#include "primes.c"


int is_pandigital(long number, int digits) {

    digits++;
    if(digits > 9) digits = 9;
    int count[9] = {0};

    while(number) {
        count[number % 10]++;
        number /= 10;
    }

    // digit 0 doesn't count for pandigital
    int x = 1;
    while(x < digits && count[x] == 1) {
        x++;
    }

    // also 0's are not allowed
    return x == digits && !count[0];
}

int main() {

    long primes[get_primes_cap()];
    int numPrimes = get_primes(0, 0, primes);

    long highest = 0;
    long *p = primes;
    char num[10];
    int length;

    while ((++p - primes) < numPrimes) {

        length = sprintf(num, "%ld", *p);
        if(is_pandigital(*p, length)) {
            highest = *p;
        }
    }

    printf("%ld\n", highest);

    return 0;
}