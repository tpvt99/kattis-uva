#include <iostream>
#define MAX_VALUE 1e9

int main() {
    int n;
    int m;

    scanf("%d", &n);
    int* teaPrices = (int *) malloc(sizeof(int) * n);

    int oldN = 0, oldM = 0;
    while (oldN++ < n) {
        int temp;
        scanf("%d", &temp);
        teaPrices[oldN-1] = temp;
    }

    scanf("%d", &m);
    int* toppingPrices = (int *) malloc(sizeof(int) * m);
    while (oldM++ < m) {
        int temp;
        scanf("%d", &temp);
        toppingPrices[oldM-1] = temp;
    }

    int minPrice = MAX_VALUE;
    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            int toppingPairIndex;
            scanf("%d", &toppingPairIndex);
            minPrice = std::min(minPrice, teaPrices[i] + toppingPrices[toppingPairIndex-1]);
            //printf("tea %d topping %d min price: %d\n", teaPrices[i], toppingPrices[toppingPairIndex-1], minPrice);
        }
    }

    //if (minPrice == MAX_VALUE) {
        //for (int i = 0; i < n; i++)
            //minPrice = std::min(minPrice, teaPrices[i]);
    //}

    int money;
    scanf("%d", &money);
    int a = money / minPrice;
    printf("%d\n", a == 0 ? 0 : a-1);

    return 0;
}