#include <stdio.h>

void fill_grid(int grid[20][20]) {

    FILE *fp = fopen("11pe", "r");
    int x, y;
    char num[2] = {'\0'};
    char c;

    for(y = 0; y < 1; y++) {
        for(x = 0; x < 1; x++) {
            while((c = getc(fp)) != '\n') {
                num[x++] = c;
                if(x == 2) {
                    printf("%s ", num);
                    x = 0;
                }
            }
        }
        printf("\n");
    }
    fclose(fp);
}

int main() {

    int grid[20][20];
    fill_grid(grid);

    return 0;
}