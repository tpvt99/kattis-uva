#include <iostream>

int main() {
    char c[3];
    int array[13] = {0};
    while (true) {
        int m = scanf("%2[A-Z0-9] ", c);
        if (m == EOF)
            break;
        switch(c[0]) {
            case 'A':
                array[0] += 1;
                break;
            case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                array[c[0] - '1'] += 1;
                break;
            case 'T':
                array[9] += 1;
                break;
            case 'J':
                array[10] += 1;
                break;
            case 'Q':
                array[11] += 1;
                break;
            case 'K':
                array[12] += 1;
                break;
        }
    }
    int maxValue = 0;
    for (int i = 0; i < 13; i++) {
        maxValue = std::max(maxValue, array[i]);
    }
    printf("%d\n", maxValue);
    return 0;
}