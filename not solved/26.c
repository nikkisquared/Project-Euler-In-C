#include <stdio.h>

int main() {

    int x;
    long double f = 1;
    for(x = 0; x < 10; x++) {
        printf("%.20Lf\n", f / x);
    }

    return 0;
}