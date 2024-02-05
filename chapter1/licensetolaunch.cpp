#include <iostream>

int main() {
    int d;
    scanf("%d", &d);
    int count = d;
    int minIndex = 0;
    int index = 0;
    int minVal = 1e9;
    while (d--) {
        int x;
        scanf("%d", &x);
        if (x < minVal) {
            minVal = x;
            minIndex = index;
        }
        index++;
    }
    printf("%d\n", minIndex);
    return 0;
}