#include <stdio.h>

int main() {

    long long a = 100;
    int x;

    for(x = 0; x < 100; x++) {
        a *= 100;
        printf("%lld\n", a);
    }
    return 0;
}