#include <stdio.h>

int main()
{
    int i;
    int sum_of_squares = 0;
    int sum = 0;
    int difference;

    for (i = 0; i <= 100; i++) {
        sum_of_squares += i * i;
        sum += i;
    }

    for (i = 0; i < sum; i++) {
        difference += sum;
    }

    difference -= sum_of_squares;

    printf("%d\n", difference);
}