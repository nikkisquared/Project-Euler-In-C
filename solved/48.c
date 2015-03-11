#include <stdio.h>

#define SIZE 11

void multiply(int digits[], int multiplicant) {

    int *n = digits;
    int carry = 0;

    while((n - digits) < SIZE) {

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

void add(int digits[], int add[]) {

    int n;
    int carry = 0;

    for(n = 0; n < SIZE; n++) {

        digits[n] += add[n];

        if(carry) {
            digits[n] += carry;
            carry = 0;
        }
        while(digits[n] >= 10) {
            digits[n] -= 10;
            carry++;
        }
    }
}

int main()
{
    int digits[SIZE] = {1};
    int temp[SIZE] = {0};
    int i, x;

    for(i = 2; i <= 1000; i++) {

        temp[0] = i;
        for(x = i; x > 1; x--)
            multiply(temp, i);
        add(digits, temp);
        // reset temp for the next go
        for(x = 0; x < SIZE; x++)
            temp[x] = 0;
    }

    for(i = 9; i >= 0; i--) {
        printf("%d", digits[i]);
    }
    printf("\n");

    return 0;
}