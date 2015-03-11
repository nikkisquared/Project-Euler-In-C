#include <stdio.h>

int is_permutation(long first, long second, int length) {
    /* assumes strings are the same length */

    int firstDigits[10] = {0};
    int secondDigits[10] = {0};
    int c;

    for(c = 0; c < length; c++) {
        firstDigits[first % 10]++;
        secondDigits[second % 10]++;
        first /= 10;
        second /= 10;
    }

    for(c = 0; c < 10; c++)
        if(firstDigits[c] != secondDigits[c])
            return 0;
    return 1;
}

int main() {

    long n = 0;
    int multi, length;
    int found = 0;
    char num[20];


    while(!found) {
        n++;
        length = sprintf(num, "%ld", n);
        if(length != sprintf(num, "%ld", n * 6))
            continue;

        multi = 1;
        while(multi <= 6 && (found = is_permutation(n, n * multi, length)))
            multi++;
    }

    printf("%ld\n", n);

    return 0;
}