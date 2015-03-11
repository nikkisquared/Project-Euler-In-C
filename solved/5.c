#include <stdio.h>

int main() {
    
    int i = 0;
    int number = 0;
    int divisible = 1;
    int highest_divider = 20;

    while (divisible) {

        // number must be divisible by 20
        number += highest_divider;
        divisible = 0;

        // number is always going to be divisible by 
        // 1, 2, and 20 no matter what
        for (i = 3; i <= highest_divider - 1; i++) {
            divisible += number % i;
        }
    }

    printf("%d\n", number);

    return 0;
}