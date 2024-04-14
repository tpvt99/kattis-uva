#include <stdio.h>
#include <stdlib.h>

int main() {
    int P;
    scanf("%d", &P);
    while (P-- > 0) {
        int k;
        scanf("%d", &k);

        int* array = (int*) malloc(sizeof(int) * 20);
        for (int i = 0; i < 20; i++) {
            int temp;
            scanf("%d", &temp);
            array[i] = temp;
        }

        // First student is selected
        // Processing from 2nd onwards
        int steps = 0;
        for (int i = 1; i < 20; i++) {
            int j = i;
            int selected = array[i];
            while (j > 0) {
                // If selected one is smaller than in line, we should swap
                // so that selected on should come sooner
                if (array[j-1] > selected) {
                    array[j] = array[j-1];
                    steps++;
                } else
                    break;
                j--;
            }
            array[j] = selected;
        }
        //for (int i = 0; i < 20; i++) {
            //printf("%d ", array[i]);
        //}
        //printf("\n");
        printf("%d %d\n", k, steps);
    }

    return 0;
}