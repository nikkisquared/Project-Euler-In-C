#include <stdio.h>

void multiply(int digits[], int multiplicant) {

    int *n = digits;
    int carry = 0;

    while((n - digits) < 200) {

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
}

int sum_digits(int digits[]) {

    int d;
    int sum = 0;

    for(d = 0; d < 200; d++) {
        sum += digits[d];
    }

    return sum;
}

int main() {

    int digits[200] = {0};
    int a, b, p, sum, maxSum;

    for(a = 2; a < 100; a++) {
        for(b = 2; b < 100; b++) {

            digits[0] = a;
            for(p = b; p > 1; p--) {
                multiply(digits, a);
            }
            sum = sum_digits(digits);
            if(sum > maxSum) maxSum = sum;
        }
    }

    printf("%d\n", sum);

    return 0;
}