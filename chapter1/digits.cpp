#include <iostream>
#include <cstring>

int main() {
    char c[1000000+1];
    while (scanf("%[0-9]\n", c) != 0) {
        // Very special case
        if (strcmp(c, "1") == 0){
            printf("1\n");
            continue;
        }

        int count = 1;
        while (strlen(c) > 1) {
            int temp = strlen(c);
            snprintf(c, sizeof(c), "%d", temp);
            count++;
        }
        printf("%d\n", count+1);
    }
    return 0;
}