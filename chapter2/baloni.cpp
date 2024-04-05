#include <iostream>
#include <map>

int main() {
    int n;
    scanf("%d\n", &n);
    std::map<int, int> heightFreq;
    while (n-- > 0) {
        int temp;
        scanf("%d", &temp);
        // If the different height with no arrow, must adding, and decrease because this baloon is shot
        if (heightFreq.find(temp) == heightFreq.end()) {
            heightFreq[temp-1] += 1;
        } else {
            // If the arrow is at height, then minus arrow now
            heightFreq[temp] -= 1;
            if (heightFreq[temp] == 0)
                heightFreq.erase(temp);
            // Then add the next arrow at below height
            heightFreq[temp-1] += 1;
        }
    }
    int answer = 0;
    for (auto it = heightFreq.begin(); it != heightFreq.end(); it++)
        answer += it->second;
    printf("%d", answer);
    return 0;
}