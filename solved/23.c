#include <stdio.h>
#include <math.h>

#define NUMERIC_CAP 28124
// how many abundant numbers there are below NUMERIC_CAP
#define ABUNDANTS_CAP 6964

/* to compile: gcc 23.c -o 23 -lm */

int sum_of_divisors(int number) {

    // assume number is divisible by 1
    int sum = 1;
    int n;

    for(n = 2; n <= sqrt(number); n++) {
        if(number % n == 0) {
            sum += n;
            if(n != number / n) sum += (number / n);
        }
    }

    return sum;
}

int is_abundant_sum(long number, int abundants[]) {

    int x = 0;
    int y = 0;
    for(x = 0; x < ABUNDANTS_CAP && abundants[x] < number; x++) {
        for(y = 0; y < ABUNDANTS_CAP && abundants[y] < number; y++) {
            if(number == abundants[x] + abundants[y]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    int abundants[ABUNDANTS_CAP];
    int nonAbundantSums[NUMERIC_CAP] = {0};
    int current = 0;
    int n;

    // finds all abundant numbers
    for(n = 1; n < NUMERIC_CAP; n++) {
        if(sum_of_divisors(n) > n) {
            abundants[current++] = n;
        }
    }

    long sum;
    for(n = 1; n < NUMERIC_CAP; n++) {
        if(!is_abundant_sum(n, abundants)) sum += n;
    }
    
    printf("%ld\n", sum);

    return 0;
}