#include <iostream>

int main() {
    int n;
    scanf("%d", &n);

    int count = 0;
    int sum = 0;
    while (n-- > 0) {
        int x;
        scanf("%d", &x);
        if (x >= 0) {
            sum += x;
            count += 1;
        }
    }

    printf("%.3f", ((float) sum) / count);
    return 0;
}