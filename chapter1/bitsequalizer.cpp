#include <iostream>

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <=n; i++) {
        char s[101];
        char t[101];
        scanf("%[?01]\n", s);
        scanf("%[?01]\n", t);

        // Check how many pairs of 0-1 and 1-0 and ?-0, ?-1
        int index = 0;
        int pair10 = 0;
        int pair01 = 0;
        int q0 = 0;
        int q1 = 0;
        while (s[index]) {
            if (s[index] == '0' && t[index] == '1'){
                pair01 += 1;
            } else if (s[index] == '1' && t[index] == '0') {
                pair10 += 1;
            } else if (s[index] == '?' && t[index] == '1') {
                q1 += 1;
            } else if (s[index] == '?' && t[index] == '0') {
                q0 += 1;
            }
            index++;
        }
        if (pair01 == pair10) {
            printf("Case %d: %d\n", i, q1+q0+pair01);// swap pair + change ? to 0 + change ? to 1
        } else if (pair01 < pair10) {
            int diff = pair10 - pair01;
            // 10 can swap with ?1 but cannot swap with ?0
            if (diff <= q1) {
                printf("Case %d: %d\n", i, pair01 + diff + q1+q0); // swap pair + swap ? + change ?
            } else {
                printf("Case %d: -1\n", i); // cannot make it equal
            }
        } else if (pair01 > pair10) {
            int diff = pair01 - pair10;
            printf("Case %d: %d\n", i, diff + pair10 + q1 + q0); // swap pair + + change ? + change 0
        }
    }

    return 0;
}