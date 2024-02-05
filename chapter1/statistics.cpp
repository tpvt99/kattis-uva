#include <iostream>
#include <algorithm>

int main() 
{
    int d;
    int count = 1;
    while (scanf("%d", &d) != EOF) {
        int minVal = 1e9;
        int maxVal = -1e9;
        while (d--) {
            int v;
            scanf("%d", &v);
            minVal = std::min(minVal, v);
            maxVal = std::max(maxVal, v);
        }
        printf("Case %d: %d %d %d\n", count++, minVal, maxVal, maxVal-minVal);
    }

    return 0;
}