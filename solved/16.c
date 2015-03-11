#include <stdio.h>

unsigned long long sum_digits(int digits[]) {

    int *n = digits;
    unsigned long long sum = 0;

    while((n - digits) < 1000) {
        sum += *n++;
    }

    return sum;
}

void double_it(int digits[]){

    int *n = digits;
    int carry = 0;

    while((n - digits) < 1000) {

        *n *= 2;
        if(carry) {
            (*n)++;
            carry = 0;
        }
        if(*n >= 10) {
            *n -= 10;
            carry = 1;
        }
        n++;
    }

    if(carry) *n = 1;
}

int main()
{
    int digits[1000] = {1};
    int i;

    for(i = 0; i < 1000; i++) {
        double_it(digits);
    }

    printf("%llu\n", sum_digits(digits));

    return 0;
}