#include <iostream>
#include <cstring>

int main() {
    int maxPeople;
    int events;
    scanf("%d%d\n", &maxPeople, &events);
    int curPeople = 0;
    int reject = 0;
    while (events-- > 0) {
        char c[6];
        int x;
        scanf("%[a-z]%d\n", c, &x);
        if (strcmp(c, "enter") == 0) {
            if (curPeople + x <= maxPeople) {
                curPeople += x;
            } else {
                reject+=1;
            }
        } else {
            curPeople -= x;
        }
    }

    printf("%d\n", reject);
}