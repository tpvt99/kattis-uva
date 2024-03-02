#include <iostream>
#include <cstring>

bool isCombo(char *str, int index) {
    if (str[index] == '\0' || str[index+1] == '\0' || str[index+2] == '\0')
    {
        return false;
    }
    char newStr[4] = "AAA";
    for (int i = index; i < index+3; i++) {
        switch (str[i]) {
            case 'B': 
                newStr[0] = 'B';
                break;
            case 'R':
                newStr[1] = 'R';
                break;
            case 'L':
                newStr[2] = 'L';
                break;
        }
    }
    if (strcmp(newStr, "BRL") == 0)
        return true;
    return false;
}

int main() {
    char *str = (char *) malloc(sizeof(char) * 1000001);
    scanf("%[A-Z]\n", str);
    int index = 0;
    while (str[index]) {
        if (isCombo(str, index)) {
            printf("C");
            index+=3;
        } else {
            switch(str[index]) {
                case 'R':
                    printf("S");
                    break;
                case 'B':
                    printf("K");
                    break;
                case 'L':
                    printf("H");
                    break;
            }
            index+=1;
        }
    }
    return 0;
}