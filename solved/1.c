#include <stdio.h>

int main()
{
    int sum = 0;
    int number = 3;

    for (number = 3; number < 1000; number++) {
        if (number % 3 == 0 || number % 5 == 0) {
            sum = sum + number;
        }
    }

    printf("The final sum is %d\n", sum);
}