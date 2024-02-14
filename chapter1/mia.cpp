#include <iostream>

int check(int a, int b, int c, int d) {
    // return 0 if ties, 1 if player 1 wins, 2 if player 2 wins
    int p1 = a*10 + b;
    int p2 = c*10 + d;
    if (p1 == 12 && p2 == 12)
        return 0;
    if (p1 == 12 && p2 == 21)
        return 0;
    if (p1 == 21 && p2 == 12)
        return 0;
    if (p1 == 21 && p2 == 21)
        return 0;

    if (p1 == 21 || p1 == 12)
        return 1;
    if (p2 == 21 || p2 == 12)
        return 2;

    if ((a==b) && (c==d)) {
        if (p1 == p2)
            return 0;
        if (p1 > p2)
            return 1;
        if (p2 > p1)
            return 2;
    }

    if (a == b)
        return 1;
    if (c == d)
        return 2;

    if (a < b)
        p1 = b*10+a;
    if (c < d)
        p2 = d*10+c;
    if (p1 == p2)
        return 0;
    if (p1 < p2)
        return 2;
    if (p1 > p2)
        return 1;

    return 0;
}

int main() {
    int a, b, c, d;
    while (scanf("%d%d%d%d", &a, &b, &c, &d), (a || b || c || d)) 
    {
        switch(check(a,b,c,d)) 
        {
            case 0:
                printf("Tie.\n");
                break;
            case 1:
                printf("Player 1 wins.\n");
                break;
            case 2:
                printf("Player 2 wins.\n");
                break;
        }
    }
    return 0;
}