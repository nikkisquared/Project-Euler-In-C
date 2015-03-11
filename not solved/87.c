#include <stdio.h>
#include "primes.c"

#define CAP 50000000

int main() {

    long primes[get_primes_cap()];
    int numPrimes = get_primes(CAP, 0, primes);
    long *powers[3] = {primes, primes, primes};

    int incAt = 0;
    int leader = 0;
    long sum;
    long nums = 0;

    while(leader < 3) {

        sum = (long)(pow(*powers[0], 2) + pow(*powers[1], 3) + pow(*powers[2], 4));
        if(sum < CAP) nums++;

        powers[incAt]++;
        incAt++;
        incAt %= 3;

        if((powers[leader] - primes) >= numPrimes) {
            powers[leader] = primes;
            leader++;
            incAt = 0;
            if(leader == 1) powers[2] = primes;
        }
    }

    printf("%ld\n", nums);

    return 0;
}