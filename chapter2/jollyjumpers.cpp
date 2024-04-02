#include <iostream>
#include <vector>

int main() {
    while (true)
    {
        int n;
        if(scanf("%d", &n) == EOF){
            break;
        }

        std::vector<bool> arr(n-1, 0);

        int prevNum, curNum;
        scanf("%d", &prevNum);
        n--;
        while(n-- > 0) {
            scanf("%d", &curNum);
            int diff = std::abs(curNum - prevNum);
            arr[diff-1] = 1;
            prevNum = curNum;
        }

        bool isJolly = false;
        for (const bool value: arr) {
            if (!value) {
                printf("Not jolly\n");
                isJolly = true;
                break;
            }
        }
        if (!isJolly)
            printf("Jolly\n");
    }
}