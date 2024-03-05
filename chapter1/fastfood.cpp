#include <iostream>
#include <vector>
#include <map>

int main() {
    int test;
    scanf("%d", &test);

    while (test-- > 0) {
        int sumPrize = 0;
        int n;
        int m;
        scanf("%d", &n);
        scanf("%d", &m);
        std::vector<std::map<int, std::vector<int>>> priceList;
        while (n-- > 0) {
            int number;
            scanf("%d", &number);
            std::vector<int> sticker;
            while (number-- > 0) {
                int temp;
                scanf("%d", &temp);
                sticker.push_back(temp);
            }
            int price;
            scanf("%d", &price);
            std::map<int, std::vector<int>> m{{price, sticker}};
            priceList.push_back(m);
        }
        std::vector<int> tickets;
        while (m-- > 0) {
            int number;
            scanf("%d", &number);
            tickets.push_back(number);
        }
        // Loop through priceList and get min of all sticker
        for (std::map<int, std::vector<int>> priceMap : priceList) {
            for (std::map<int, std::vector<int>>::iterator itr = priceMap.begin(); itr != priceMap.end(); itr++) {
                int prize = itr->first;
                int minSticker = 100;
                for (auto index : itr->second) {
                    minSticker = std::min(tickets[index-1], minSticker);
                }
                sumPrize += minSticker * prize;
            }
        }
        printf("%d\n", sumPrize);
    }

    return 0;
}