#include <stdio.h>
#include <math.h>

/* to compile: gcc 30.c -o 30 -lm */

int main() {

    long x, n, sum;
    int p;
    long totalSum = 0;

    for(x = 10; x <= 100000000; x++)
    {
        n = x;
        sum = 0;
        while(n) {
            p = n % 10;
            sum += pow(p, 5);
            //printf("%ld | %d | %ld\n", n, p, sum);
            n /= 10;
        }
        if(sum == x) {
            totalSum += x;
            printf("new %ld | sum %ld\n", x, totalSum);
        }
    }

    return 0;
}