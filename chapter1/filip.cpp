#include <iostream>

int main() {
    int a, b;
    int flipA=0, flipB=0;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < 3; i++) {
        int lastA = a%10;
        flipA = flipA*10 + lastA;
        int lastB = b%10;
        flipB = flipB*10 + lastB;
        a = a/10;
        b = b/10;
    }
    if (flipA > flipB)
        printf("%d", flipA);
    else
        printf("%d", flipB);

    return 0;
}