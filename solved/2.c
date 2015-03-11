#include <stdio.h>

int main()
{
    int new = 0;
    int current = 2;
    int last = 1;
    int sum = 0;

    while (current < 4000000) {
        if (current % 2 == 0) {
            sum = sum + current;
        }
        new = current + last;
        last = current;
        current = new;
    }
    
    printf("The sum is %d\n", sum);
}