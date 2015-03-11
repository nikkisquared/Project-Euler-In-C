#include <stdio.h>

int collatz(long long n, int lengths[]) {

    int length = 1;
    // no information is ever lost with this cast, n is long long to prevent numerical overflows
    long initial = n;

    // checking lengths stops the collatz sequence if the current n has been calculated
    // the conditional is arranged to prevent out of bounds errors for when n is too large
    while(n > 1 && (n > 1000000 || !lengths[n])) {
        n = (n % 2 == 0) ? n / 2 : (n * 3) + 1;
        length++;
    }

    if(lengths[n]) length += lengths[n] - 1;
    lengths[initial] = length;

    return length;
}

int main() {

    long maxN, maxLength = 0;
    long long n;
    int length;
    int lengths[1000001] = {0};

    for(n = 1; n < 1000000; n++) {
        length = collatz(n, lengths);
        if(length > maxLength) {
            maxLength = length;
            maxN = n;
        }
    }

    printf("%ld\n", maxN);

    return 0;
}