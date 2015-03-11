#include <stdio.h>

#define TARGET 100

int sum_digits(int digits[]) {

    int d;
    int sum = 0;

    for(d = 0; d < TARGET; d++)
        sum += digits[d];

    return sum;
}

void reset(int digits[], int *offset) {

    int *d;
    for(d = offset; (d - digits) < TARGET; d++)
        *d = 0;
}

void print_digits(int digits[]) {

    int d;
    printf("\n");
    for(d = 0; d < TARGET; d++)
        printf("%d | ", digits[d]);
}

int main() {

    int digits[TARGET] = {1};
    reset(digits, &digits[1]);
    int addAt = 1;
    int incAt = 0;
    int ways = 0;

    while(digits[0] < TARGET) {

        while(sum_digits(digits) < TARGET) {
            //print_digits(digits);
            digits[addAt] = 1;
            addAt++;
        }
        if(sum_digits(digits) == TARGET) {
            ways++;
            //print_digits(digits);
            printf("bam! %d", ways);
        }
        else incAt = 0;
        reset(digits, &digits[incAt + 1]);
        digits[incAt]++;
        addAt = incAt + 1;
        incAt++;
    }

    //printf("%d\n", ways);
    printf("\n");

    return 0;
}