#include <stdio.h>
#include <math.h>

#define CAP 10000

/* to compile: gcc 21.c -o 21 -lm */

int sum_of_divisors(int number) {
    
    // assume number is divisible by 1
    int sum = 1;
    int n;

    for(n = 2; n <= sqrt(number); n++) {
        if(number % n == 0) {
            sum += n + (number / n);
        }
    }

    return sum;
}

int main() {

    int amicable[CAP] = {0};
    int number;
    int partner;

    for(number = 1; number < CAP; number++) {
        partner = sum_of_divisors(number);
        if(number != partner && partner < CAP &&
            number == sum_of_divisors(partner)) {
            amicable[number] = 1;
            amicable[partner] = 1;
        }
    }

    int n;
    int sum = 0;

    for(n = 0; n < CAP; n++) {
        if(amicable[n]) {
            sum += n;
        }
    }

    printf("%d\n", sum);

    return 0;
}