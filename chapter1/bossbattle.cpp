#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    switch(n) {
        case 1: case 2: case 3:
            printf("1");
            break;
        default:
            printf("%d", n-2);
    }
    return 0;
}