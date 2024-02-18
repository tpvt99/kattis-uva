#include <iostream>

int main() {
    char c[31];
    scanf("%[a-z]\n", c);
    for (int i = 0; i <31; i++) {
        if (c[i] == '\0') {
            printf("no hiss");
            break;
        }
        if (c[i] == 's' && c[i+1] == 's') {
            printf("hiss");
            break;
        }
    }
    return 0;
}