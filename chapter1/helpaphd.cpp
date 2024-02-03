#include <iostream>

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC-- > 0) {
        if (scanf("P=NP\n") == 0) {
            printf("skipped\n");
        } else {
            int a, b;
            scanf("%d+%d\n", &a, &b);
            printf("%d\n", a+b);
        }
    }
    return 0;
}