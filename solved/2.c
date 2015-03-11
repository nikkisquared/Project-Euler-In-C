#include <stdio.h>

int main() {

    int sum = 0;
    int current = 2;
    int last = 1;
    int temp;

    while (current < 4000000) {
        if (current % 2 == 0) sum += current;
        temp = current + last;
        last = current;
        current = temp;
    }
    
    printf("%d\n", sum);

    return 0;
}