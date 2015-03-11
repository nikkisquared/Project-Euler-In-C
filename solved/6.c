#include <stdio.h>

int main() {
    
    int i;
    int sum_of_squares = 0;
    int square_of_sum = 0;
    int sum = 0;

    for (i = 0; i <= 100; i++) {
        sum_of_squares += i * i;
        sum += i;
    }

    for (i = 0; i < sum; i++) {
        square_of_sum += sum;
    }

    printf("%d\n", square_of_sum - sum_of_squares);

    return 0;
}