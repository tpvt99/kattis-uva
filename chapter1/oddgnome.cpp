#include <iostream>

int main() {
    int d;
    scanf("%d", &d);
    int printFirst = false;
    while (d--) {
        int n;
        scanf("%d", &n);
        int prev = 0;
        scanf("%d", &prev);
        n--;
        int count = 2;
        while (n--) {
            int x;
            scanf("%d", &x);
            //printf("x is %d while prev: %d\n", x, prev);
            if (x != prev+1) {
                if (!printFirst) {
                    printf("%d", count);
                    printFirst = true;
                } else {
                    printf(" %d", count);
                }
                // scanf till eol
                scanf(" %*[^\n]");
                break;
            } else {
                prev = x;
            }
            count++;
        }
    }
    return 0;
}