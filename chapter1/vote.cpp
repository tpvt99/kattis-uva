#include <iostream>

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n;
        scanf("%d", &n);
        int *scores = (int *) malloc(sizeof(int) * n);
        int sumScore = 0;
        int maxScore = 0;
        int maxIndex = 0;
        for (int i = 0; i < n; i++) {
            int score;
            scanf("%d", &score);
            sumScore += score; 
            scores[i] = score;
            if (score > maxScore) {
                maxScore = score;
                maxIndex = i;
            }
        }
        // Loop once more to check if most vote has another equal
        bool topEqual = false;
        for (int i = 0; i < n; i++) {
            if (i != maxIndex && scores[i] == maxScore) {
                topEqual = true;
            }
        }
        if (topEqual) {
            printf("no winner\n");
        } else {
            int avg = sumScore / 2;
            if (maxScore > avg) {
                printf("majority winner %d\n", maxIndex+1);
            } else {
                printf("minority winner %d\n", maxIndex+1);
            }
        }
    }

    return 0;
}