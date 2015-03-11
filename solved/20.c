#include <stdio.h>

unsigned long long sum_digits(int digits[]) {

    int *n = digits;
    unsigned long long sum = 0;

    while((n - digits) < 1000) {
        sum += *n++;
    }

    return sum;
}

void multiply(int digits[], int multiplicant) {

    int *n = digits;
    int carry = 0;

    while((n - digits) < 1000) {

        *n *= multiplicant;
        if(carry) {
            (*n) += carry;
            carry = 0;
        }
        while(*n >= 10) {
            *n -= 10;
            carry += 1;
        }
        n++;
    }

    if(carry) *n = 1;
}

int main()
{
    int digits[1000] = {1};
    int i;

    for(i = 2; i <= 100; i++) {
        multiply(digits, i);
    }

    printf("%llu\n", sum_digits(digits));

    return 0;
}