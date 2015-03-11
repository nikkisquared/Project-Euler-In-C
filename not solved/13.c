#include <stdio.h>

#define ADDING 50
#define EXTRA 10
#define TOTAL ADDING+EXTRA

void sum(int digits[], int add[]) {

    int n;

    for(n = 0; n <= ADDING; n++)
        digits[n + EXTRA] += add[n];

    int carry = 0;
    for(n = TOTAL - 1; n >= 0; n--) {
        if(carry) {
            digits[n] += carry;
            carry = 0;
        }
        if(digits[n] >= 10) {
            digits[n] -= 10;
            carry = 1;
        }
    }
}

void print_number(int digits[], int length, char *msg) {

    int d;
    printf("%s", msg);
    for(d = 0; d < length; d++)
        printf("%d", digits[d]);
    printf("\n");
}

int main() {

    int number;
    int digits[TOTAL] = {0};
    int add[ADDING];
    int n;
    int d;

    FILE *fp = fopen("13pe", "r");
    for(n = 0; n < 50; n++) {

        for(d = 0; d < ADDING; d++) {
            sprintf(fp, "%1d", &number);
            add[d] = number;
        }
        print_number(add, ADDING, "ADD: ");
        sum(digits, add);
        print_number(digits, TOTAL, "SUM:");
    }
    for(d = 0; d < TOTAL; d++)
        printf("%d", digits[d]);
    printf("\n");

    fclose(fp);
    return 0;
}