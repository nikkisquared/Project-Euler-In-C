#include <stdio.h>


int get_length(unsigned long long number) {

    int length = 0;
    while(number) {
        number /= 10;
        length++;
    }

    return length;

}

void fibo(unsigned long long previous, unsigned long long current, int count, int lastRecord, int length) {

    unsigned long long temp = previous;
    previous = current;
    current += temp;
    count++;

    if(!current) current = 1;

    int newLength = get_length(current);
    if(newLength > length) {
        printf("fibo %2d has %2d digits\n", count, newLength);
        lastRecord = count;
    }

    if(current < 1000000000000000000)
        fibo(previous, current, count, lastRecord, newLength);

}

int main() {

    //fibo(0, 0, 0, 0, 0);
    //printf("----------------\n");
    int digits = 2;
    int fibo = 7;
    int fives = 2;
    unsigned long long pattern = 34434434344344344;
    // reversal of the pattern for modulo operations
    /*              */ pattern = 44344344343443443;
    unsigned long long copy = 0;

    while(fibo < 1000) {
        if(!copy) copy = pattern;
        if(!fives) {
            fives = copy % 10;
            copy /= 10;
            fibo += 4;
            digits++;
        } else {
            fives--;
            fibo += 5;
            digits++;
        }
        //printf("fibo %2d has %2d digits!\n", fibo, digits);
    }
    printf("%d\n", digits - ((fibo == 1000) ? 0 : 1));

    return 0;
}