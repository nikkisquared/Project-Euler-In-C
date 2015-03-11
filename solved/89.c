#include <stdio.h>
#include <math.h>

#define SIZE 568

long next_step(long n) {

    long next = 0;

    while(n) {
        next += pow(n % 10, 2);
        n /= 10;
    }
    return next;
}

int main() {

    int leadsTo89[SIZE] = {0};
    leadsTo89[89] = 1;

    long n, next;

    // 0 and 1 are instant dead ends
    for(n = 2; n < SIZE; n++) {
        next = n;
        while((next = next_step(next)) != 1 && !leadsTo89[next])
            ;
        if(next != 1) leadsTo89[n] = 1;
    }

    long total = 0;
    for(n = 2; n < 10000000; n++) {
        total += leadsTo89[next_step(n)];
    }
    printf("%ld\n", total);

    return 0;
}