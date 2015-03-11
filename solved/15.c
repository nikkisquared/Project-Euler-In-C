#include <stdio.h>

// this deals with the points of the grid, and not the grid squares,
// so SIZE has to be one greater to account for every point
#define SIZE 21

long long max(long long x, long long y) {
    return x > y ? x : y;
}

int main() {

    long long grid[SIZE][SIZE];
    long long x, y;
    long long paths = 1;

    for(x = 0; x < SIZE; x++) {
        for(y = 0; y < SIZE; y++) {

            if(x == SIZE - 1 || y == SIZE - 1) {
                // far edges in either direction have no options
                grid[x][y] = 0;
            } else if(x == 0 || y == 0) {
                // top/left edges only give one branch
                grid[x][y] = 1;
                paths++;
            } else {
                // value is the max number of steps it takes to get here
                // which is also how many paths branch through it
                grid[x][y] = grid[x-1][y] + grid[x][y-1];
                paths += grid[x][y];
            }
        }
    }
    printf("%lld\n", paths);

    return 0;
}