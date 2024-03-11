#include <iostream>

int returnValue(char number, char suit, char dominantSuit) {
    switch (number) {
       case 'A': return 11;
       case 'K': return 4;
       case 'Q': return 3;
       case 'J': return (suit == dominantSuit) ? 20 : 2;
       case 'T': return 10;
       case '9': return (suit == dominantSuit) ? 14 : 0;
       case '8': return 0;
       case '7': return 0;
    }
    return 0;
}

int main() {
    int c; char dominantSuit;
    scanf("%d ", &c);
    scanf("%c\n", &dominantSuit);
    int sum = 0;
    for (int i = 0; i < c*4; i++) {
        char a, b;
        scanf("%c%c\n", &a, &b);
        sum += returnValue(a, b, dominantSuit);
    }

    printf("%d\n", sum);

    return 0;
}