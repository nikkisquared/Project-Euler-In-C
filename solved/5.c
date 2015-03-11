#include <stdio.h>

int main()
{
    int i = 0;
    int number = 0;
    int divisible = 0;
    int highest_divider = 20;

    while (!divisible) {

        number = number + highest_divider;

        divisible = 1;

        for (i = 1; i <= highest_divider; i++) {
            if (number % i != 0) {
                divisible = 0;
            }
        }
    }

    printf("The smallest number possible is %d\n", number);
}