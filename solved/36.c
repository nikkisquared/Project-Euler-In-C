#include <stdio.h>

int is_palindrome(char num[], int length) {

    char *start = num;
    char *end = num;
    end += length - 1;
    int isPalindrome = 1;

    do {
        isPalindrome = *start == *end;
    } while(isPalindrome && (end-- - start++) > 0);

    return isPalindrome;
}

int itob(long n, char bin[]) {

    int length = 0;
    int leading1 = 0;
    // largest binary bit needed
    long bitSize = 524288;

    while(bitSize) {
        if(n >= bitSize) {
            n -= bitSize;
            bin[length++] = '1';
            leading1 = 1;
        } else if(leading1) {
            bin[length++] = '0';
        }
        bitSize /= 2;
    }

    bin[length] = '\0';

    return length;
}

int main() {

    long sum = 0;
    long n;
    // largest space ever needed
    char num[7];
    char bin[20];
    int numLength, binLength;

    for (n = 1; n < 1000000; n++) {
        numLength = sprintf(num, "%ld", n);
        binLength = itob(n, bin);

        if(is_palindrome(num, numLength) &&
            is_palindrome(bin, binLength))
            sum += n;
    }

    printf("%ld\n", sum);

    return 0;
}