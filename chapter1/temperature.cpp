#include <iostream>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    // Formula would be x + ys = s, where s is the result
    if (x == 0 && y == 1) { // s = s
        printf("ALL GOOD");
    } else if (x!= 0 && y == 1) { // x = 0
        printf("IMPOSSIBLE");
    } else {
        printf("%.6f", static_cast<float>(x)/(1-y));
    }

    return 0;
}