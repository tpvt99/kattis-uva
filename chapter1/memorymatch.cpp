#include <iostream>
#include <cstring>
#include <map>
#include <set>

int main() {
    int n;
    int turns;
    scanf("%d", &n);
    scanf("%d", &turns);

    std::map<std::string, std::set<int>> cardMap;
    int numCardMatches = 0;
    while (turns-- > 0) {
        int i, j;
        char word1[21], word2[21];
        scanf("%d%d %20[a-z] %20[a-z]\n", &i, &j, word1, word2);
        if (strcmp(word1, word2) == 0) {
            // Remove this word from cardMap
            std::string strWord = std::string(word1);
            cardMap.erase(strWord);
            numCardMatches += 2;
        } else {
            std::string strWord1 = std::string(word1);
            cardMap[strWord1].insert(i);
            std::string strWord2 = std::string(word2);
            cardMap[strWord2].insert(j);
        }
    }

    int result = 0;
    int sizeOne = 0;
    for (auto itr = cardMap.begin(); itr != cardMap.end(); itr++)
    {
        if (itr->second.size() == 2) {
            result+=1;
            numCardMatches += 2;
        } else if (itr->second.size() == 1) {
            sizeOne += 1;
        }
    }
    int unopenCardLeft = n - numCardMatches - sizeOne;
    if (sizeOne == unopenCardLeft) {
        result += sizeOne;
    } else if (unopenCardLeft == 2) {
        result += 1;
    }

    printf("%d\n", result);

    return 0;
}