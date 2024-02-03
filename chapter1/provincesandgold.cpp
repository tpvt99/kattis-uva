#include <iostream>

int main() {
    int g,s,c;
    scanf("%d %d %d", &g, &s, &c);
    int buyingpower = g*3 + s*2 + c*1;
    if (buyingpower >= 8) {
        printf("Province or ");
    } else if (buyingpower >= 5) {
        printf("Duchy or ");
    } else if (buyingpower >= 2) {
        printf("Estate or ");
    }

    if (buyingpower >= 6) {
        printf("Gold");
    } else if (buyingpower >= 3) {
        printf("Silver");
    } else {
        printf("Copper");
    }

    return 0;
    
}