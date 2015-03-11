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

int main() {

    int largest = 0;
    int x, y, product, length;
    // largest space ever needed
    char num[7];

    for (x = 1000; x >= 100; x--) {
        for (y = x; y >= 100; y--) {
            product = x * y;
            length = sprintf(num, "%d", product);

            if(is_palindrome(num, length) && product > largest)
                largest = product;
        }
    }

    printf("%d\n", largest);

    return 0;
}