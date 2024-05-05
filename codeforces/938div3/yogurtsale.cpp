#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n-- > 0)
    {
        int x, a, b;
        scanf("%d%d%d", &x, &a, &b);
        // If two single is better than promotion than just use 2
        // e.g., two buy separately costs 10 rather than 11
        if (2*a <= b) {
            printf("%d\n", x*a);
        } else {
            // two separately costs 10, two together cost 9
            int cost = (x%2) * a + int(x/2) * b;
            printf("%d\n", cost);
        }
    }

    return 0;
}