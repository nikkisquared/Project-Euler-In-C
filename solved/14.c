#include <stdio.h>

int collatz(long n) {

    int length = 1;

    while(n != 1) {
        n = (n % 2 == 0) ? n / 2 : (n * 3) + 1;
        length++;
    }

    return length;
}

int main() {

    long nLongest, lenLongest = 0;
    long n;
    int length;

    for(n = 1; n < 1000000; n++) {
        length = collatz(n);
        if(length > lenLongest) {
            lenLongest = length;
            nLongest = n;
        }
    }

    printf("%ld has a collatz length of %ld.\n",
            nLongest, lenLongest);

    return 0;
}