#include <iostream>
#include <cstdlib>

int main() {
    int n;
    scanf("%d", &n);
    while (n-- > 0) {
        int x;
        scanf("%d", &x);
        if (std::abs(x) % 2 == 0) {
            printf("%d is even\n", x);
        } else {
            printf("%d is odd\n", x);
        }
    }
    return 0;
}