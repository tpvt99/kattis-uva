#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <cstring>

int main() {
    int n;
    while(scanf("%d\n", &n), n != 0) {
        std::vector<char> vec{32, '?'};
        while (n-- > 0) {
            char* instruction = (char *) malloc(sizeof(char) * 6);
            if (strcmp(instruction, "SET")) {
                // Reading 1 number
                int bit;
                scanf("%d\n", &bit);
                vec[bit] = '1';
            }
            if (strcmp(instruction, "CLEAR")) {
                // Reading 1 bit
                int bit;
                scanf("%d\n", &bit);
                vec[bit] = '0';
            }
            if (strcmp(instruction, "OR")) {
                int bit1, bit2;
                scanf("%d%d\n", &bit1, &bit2);
                // If a bit is 1, then OR must set bit1 to 1
                if (vec[bit1] == '1' || vec[bit2] == '1') {
                    vec[bit1] = '1';
                } else if (vec[bit1] == '0' && vec[bit2] == '?') {
                    vec[bit1] = '?';
                }
            }
            if (strcmp(instruction, "AND")) {
                int bit1, bit2;
                scanf("%d%d\n", &bit1, &bit2);
                if (vec[bit1] == '0' || vec[bit2] == '0') {
                    vec[bit1] = '0';
                } else if (vec[bit2] == '?') {
                    vec[bit1] = '?';
                }
            }
        } 
    }
}