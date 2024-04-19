#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <cstring>

int main() {
    int n;
    int i = 0;
    while(scanf("%d\n", &n), n != 0) {
        std::vector<char> vec(32, '?');
        while (n-- > 0) {
            char* instruction = (char *) malloc(sizeof(char) * 6);
            scanf("%[A-Z]", instruction);
            if (strcmp(instruction, "SET") == 0) {
                // Reading 1 number
                int bit;
                scanf("%d\n", &bit);
                vec[bit] = '1';
            }
            if (strcmp(instruction, "CLEAR") == 0) {
                // Reading 1 bit
                int bit;
                scanf("%d\n", &bit);
                vec[bit] = '0';
            }
            if (strcmp(instruction, "OR") == 0) {
                int bit1, bit2;
                scanf("%d%d\n", &bit1, &bit2);
                // If a bit is 1, then OR must set bit1 to 1
                if (vec[bit1] == '1' || vec[bit2] == '1') {
                    vec[bit1] = '1';
                } else if (vec[bit1] == '0' && vec[bit2] == '?') {
                    vec[bit1] = '?';
                }
            }
            if (strcmp(instruction, "AND") == 0) {
                int bit1, bit2;
                scanf("%d%d\n", &bit1, &bit2);
                if (vec[bit1] == '0' || vec[bit2] == '0') {
                    vec[bit1] = '0';
                } else if (vec[bit2] == '?') {
                    vec[bit1] = '?';
                }
            }
        }
        for (int i = 0; i < vec.size(); i++)
            printf("%c", vec[vec.size()-i-1]);
        printf("\n");
    }
}