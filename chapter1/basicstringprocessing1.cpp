#include <iostream>
#include <cstring>

void c_style(void) {
    char line[31];
    char text[30*10+10]; // 30 char per line, 10 lines, 9 spaces, 1 for final '\0'
    char *top = text;
    while (scanf("%30[ .a-zA-Z0-9]", line) != EOF) {
        // Using memcpy
        char subbuff[8];
        memcpy(subbuff, line, 7);
        subbuff[7] = '\0';
        if (strcmp(subbuff, ".......") == 0) {
            break;
        }
        
        // using strcpy
        strncpy(top, line, strlen(line));
        top = top + strlen(line);
        *top = ' ';
        top++;
        scanf("\n");
    }
    top--;
    *top='\0';
    printf("%s\n", text);

    return;
}

int main() {
    c_style();
    return 0;
}