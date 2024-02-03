#include <iostream>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a < b) {
        printf("Dr. Chaz will have %d piece", b-a);
        if (a < b-1) {
            printf("s");
        }
        printf(" of chicken left over!");
    } else if (a > b) {
        printf("Dr. Chaz needs %d more piece", a-b);
        if (a-1 > b) {
            printf("s");
        }
        printf(" of chicken!");
    }
    return 0;
}