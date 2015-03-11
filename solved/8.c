#include <stdio.h>

#define DIGITS 13

int main() {

    char num[DIGITS + 1] = {'0'};
    int cur = 0;
    int canTest = 0;
    char c;
    int digit, d;
    long long sum;
    long long highest = 0;
    FILE *fp = fopen("8pe", "r");

    while((c = getc(fp)) != EOF) {
        num[cur++] = c;
        
        if(cur >= DIGITS) {
            cur = 0;
            canTest = 1;
        }

        if(canTest) {
            sum = 1;
            for(d = 0; d < DIGITS; d++) {
                sscanf(&num[d], "%1d", &digit);
                sum *= digit;
            }
            if(sum > highest) highest = sum;
        }
    }
    
    fclose(fp);
    printf("%lld\n", highest);

    return 0;
}