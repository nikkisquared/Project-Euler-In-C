#include <stdio.h>

long long factorial_sum(int f) {

    if(!f) return 0;

    long long sum = 1;

    do {
        sum *= f;
    } while(--f);

    return sum;
}

int main() {

    int f;
    long long n, sum;
    unsigned long long x = 10;
    unsigned long long totalSum = 0;

    while(1) {
        if(x % 50000000 == 0) printf("%llu\n", x);
        n = x;
        sum = 0;
        while(n) {
            f = n % 10;
            sum += factorial_sum(f);
            //printf("%ld | %d | %ld\n", n, f, sum);
            n /= 10;
        }
        if(sum == x) {
            totalSum += x;
            printf("new %lld | sum %lld\n", x, totalSum);
        }
        x++;
    }
    //printf("%ld\n", totalSum);

    return 0;
}