#include <iostream>
#include <cstring>

int main() {
    int n;
    char type;
    char s[6];

    int allTypes[26] = {0};
    int score = 0;
    int solved = 0;
    while (scanf("%d %c %s\n", &n, &type, s) == 3) {
        int index = static_cast<int>(type) - static_cast<int>('A');
        if (strcmp(s, "right") == 0)
        {
            score += n + allTypes[index];
            solved += 1;
        }
        else if (strcmp(s, "wrong") == 0)
        {
            allTypes[index] += 20;
        }
    }
    printf("%d %d\n", solved, score);
    return 0;
}