#include <stdio.h>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <vector>

bool customCompare(std::string str1, std::string str2) {
    if (str1[0] != str2[0])
        return str1[0] < str2[0];
    if (str1[1] != str2[1])
        return str1[1] < str2[1];

    // Can return true make it stable
    // assuming that str1 is appearing first in original list
    return false;
}

int main() {
    char* line = (char*) malloc(sizeof(char) * 201);

    bool firstTimeJustForPrinting = false;
    while (scanf("%[a-zA-Z0-9]\n", line) != EOF) {
        if (line[0] == '0')
            break;

        if (firstTimeJustForPrinting)
            printf("\n");

        int num;
        sscanf(line, "%d", &num);
        std::vector<std::string> array;
        while(num-- > 0) {
            scanf("%[a-zA-Z]\n", line);
            array.emplace_back(std::string(line));
        }

        std::sort(array.begin(), array.end(), customCompare);

        for (const auto s: array) {
            printf("%s\n", s.c_str());
        }
        firstTimeJustForPrinting = true;
    }

    return 0;
}