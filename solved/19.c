#include <stdio.h>




int main()
{
    // first day is a tuesday
    int day = 2;
    int month, year;
    int months[] = {31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 30};
    int sundays = 0;

    for(year = 1901; year < 2001; year++) {
        for(month = 0; month < 12; month++) {

            day += months[month];
            if(month == 1 && !(year % 4)) day++;
            day %= 7;

            sundays += (!day);
        }
    }
    printf("%d\n", sundays);
}