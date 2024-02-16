#include <iostream>
#include <cstdlib>
#include <cstring>

int main() {
    char *c = (char *) malloc(sizeof(char) * (1000000+1));
    while (scanf("%[0-9]*", c) != 0) {
        int count = 1;
        scanf("\n");
        while (strlen(c) > 1) {
            int temp = strlen(c);
            snprintf(c, sizeof(c), "%d", temp);
            count++;
        }
        printf("%d\n", count+1);
    }
    return 0;
}