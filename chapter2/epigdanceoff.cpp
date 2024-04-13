#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d%d\n", &n, &m);
    
    char *array = (char *) malloc(sizeof(char) * n * m);
    char dummy;
    int count = 0;
    while(scanf("%c", &dummy) != EOF) {
        if (dummy == '\n')
            continue;
        array[count++] = dummy; 
    }

    int result = 0;
    for (int col = 0; col < m; col++) {
        bool blank = true;
        for (int row = 0; row < n; row++) {
            if (array[m*row + col] == '$') {
                blank = false;
                break;
            }
        }
        if (blank)
            result+=1;
    }
    // + 1 for the the shape that not counted yet
    printf("%d\n", result+1);
}