#include <iostream>
#include <cstring>

int main() {
    int TC;
    scanf("%d\n", &TC);
    while (TC-- > 0) {
        int maxlength = 10;
        char str[maxlength];
        fgets(str, maxlength, stdin);
        // Remove \n
        str[strlen(str)-1] = '\0';
        if (strcmp(str, "P=NP") == 0)
        {
            printf("skipped\n");
        } else {
            int a, b;
            sscanf(str, "%d+%d", &a, &b);
            printf("%d\n", a+b);
        }
    }
    return 0;
}