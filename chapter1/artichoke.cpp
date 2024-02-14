#include <iostream>
#include <cmath>
#include <algorithm>

#define INF 1e9

float price(int p, int a, int b, int c, int d, int k) {
    return p * (sin(a*k + b) + cos(c*k + d) + 2);
}

int main() {
    int p, a, b, c, d, n;
    scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n);
    float hi = INF;
    float decline = 0;
    for (int i = 1; i <= n; i++) {
        float stock = price(p,a,b,c,d,i);
        if (hi == INF || stock > hi) {
            hi = stock;
        } else {
            decline = std::max(decline, hi - stock);
        }
    }
    printf("%.6f", decline);

    return 0;
}