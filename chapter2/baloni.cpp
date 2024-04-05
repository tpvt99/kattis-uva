#include <stdio.h>
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
            heightFreq[temp]+=1;
        } else {
            int freq = heightFreq[temp];
            freq--;
            if (freq == 0) {
                heightFreq.erase(temp);
                heightFreq[temp]+=1;
            } else {
                heightFreq[temp]-=1;
                heightFreq[temp]+=1;
            }
        }
    }
    int answer = 0;
    for (auto it = heightFreq.begin(); it != heightFreq.end(); it++)
        answer += it->second;
    printf("%d\n", answer);
    return 1;
}