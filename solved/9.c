#include <stdio.h>

int main() {
    
    int a;
    int b;
    int c;
    int product = 0;

    for (c = 1; c <= 1000; c++) {
        for (b = 1; b < c; b++) {
            for (a = 1; a < b; a++) {
                if (a*a + b*b == c*c && a + b + c == 1000) {
                    product = a * b *c;
                }
            }
        }
    }

    printf("%d\n", product);

    return 0;
}