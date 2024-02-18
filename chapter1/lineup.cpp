#include <iostream>
#include <cstring>

int main() {
    int n;
    scanf("%d\n", &n);
    // Comparing first 2 names
    int increasing = 0;
    char s1[13];
    char s2[13];
    scanf("%12[A-Z]\n", s1);
    scanf("%12[A-Z]\n", s2);
    if (strcmp(s2, s1) > 0) {
        // s2 is bigger, which mean increasing
        increasing = 1;
    }
    n-=2;
    strcpy(s1, s2);
    while (n-- > 0) {
        scanf("%12[A-Z]\n", s2);
        if (increasing == 1 && strcmp(s2, s1) < 0){
            printf("NEITHER");
            increasing = -1;
            break;
        } else if (increasing == 0 && strcmp(s2, s1) > 0) {
            printf("NEITHER");
            increasing = -1;
            break;
        }
        strcpy(s1, s2);
    }
    if (increasing == 1) {
        printf("INCREASING");
    } else if (increasing == 0) {
        printf("DECREASING");
    }

    return 0;
}