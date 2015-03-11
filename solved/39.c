#include <stdio.h>

int find_solutions(int n) {

    int solutions = 0;
    int a, b, c;

    for(a = 1; a <= n; a++) {
        for(b = 1; b <= a; b++) {
            for(c = 1; c <= n; c++) {

                if(a + b + c != n || c > a + b)
                    continue;
                if(a*a + b*b == c*c)
                    solutions += 1;
            }
        }
    }

    return solutions;
}

int main() {

    int p, solutions, maxP;
    int maxSolutions = 0;

    // I assume the solution is divisible by 20 to try to speed things up because
    // the highest number of solutions seems to come from numbers divisible by 20
    for(p = 20; p <= 1000; p += 20) {
        solutions = find_solutions(p);
        if(solutions > maxSolutions) {
            maxSolutions = solutions;
            maxP = p;
        }
    }

    printf("%d\n", maxP);

    return 0;
}