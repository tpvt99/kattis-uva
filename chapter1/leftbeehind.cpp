#include <iostream>

int main() {
    int a,b;
    while(scanf("%d %d", &a, &b) && (a || b)) {
        int total = a + b;
        if (total == 13) {
            printf("Never speak again.\n");
        }
        else if (a < b) {
            printf("Left beehind.\n");
        }
        else if (a > b) {
            printf("To the convention.\n");
        }
        else {
            printf("Undecided.\n");
        }
    }

    return 0;
}