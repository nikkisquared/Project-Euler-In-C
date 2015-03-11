#include <stdio.h>
#include <math.h>

#define CAP (long long)sqrt(1929394959697989990) + 1
#define MIN (long long)sqrt(1020304050607080900) - 1
#define MATCH "1_2_3_4_5_6_7_8_9_0"
#define LENGTH 19

int main() {

    char num[20];
    num[19] = '\0';
    int cur;

    long long n = MIN;
    long long found = 0;

    while(!found && n < CAP) {

        sprintf(num, "%lld", (long long)pow(n, 2));
        cur = 0;
        while(num[cur] == MATCH[cur] && cur < LENGTH)
            cur += 2;
        if(cur > LENGTH)
            found = n;
        n++;
    }

    printf("%lld\n", found);

    return 0;
}