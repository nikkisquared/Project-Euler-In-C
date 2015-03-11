#include <stdio.h>

int main() {
    
    int sum = 0;
    int number = 3;

    for (number = 3; number < 1000; number++) {
        if (number % 3 == 0 || number % 5 == 0)
            sum += number;
    }

    printf("%d\n", sum);

    return 0;
}