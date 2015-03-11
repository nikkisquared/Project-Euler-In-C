#include <stdio.h>
#include "primes.c"

int consecutive_sum_length(long *current, long *end) {

    long sum = 0;
    int length = 0;

    do {
        sum += *current;
        length++;
        current++;
    } while(sum < *end && current < end);

    return (sum == *end) ? length : 0;
}

int main() {

    long primes[get_primes_cap()];
    long numCap = 1000000;
    int numPrimes = get_primes(numCap, 0, primes);

    int length;
    int maxLength = 0;
    long answer;
    long *p = primes;
    long *start;

    while((++p - primes) < numPrimes) {

        start = &primes[1];
        while(start < p && *start < (*p / 2) &&
                (p - start) > maxLength) {
            length = consecutive_sum_length(start, p);
            if(length > maxLength) {
                maxLength = length;
                answer = *p;
            }
            start++;
        }
    }

    printf("%ld\n", answer);

    return 0;
}