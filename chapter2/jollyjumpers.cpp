#include <iostream>
#include <vector>

int main() {
    while (true)
    {
        int n;
        char dummy;
        if(scanf("%d%c", &n, &dummy) == EOF){
            break;
        }
        
        std::vector<bool> arr(400000, false);

        int prevNum, curNum;
        scanf("%d%c", &prevNum, &dummy);

        int originN = n;
        n--;
        while(n-- > 0) {
            scanf("%d%c", &curNum, &dummy);
            int diff = (int) std::abs(curNum - prevNum);
            /// @note this is edge case
            if (diff > 0)
                arr[diff-1] = true;
            prevNum = curNum;
        }

        bool isJolly = true;
        for (int i = 0; i < originN-1; i++) {
            if (!(arr[i])) {
                printf("Not jolly\n");
                isJolly = false;
                break;
            }
        }
        if (isJolly)
            printf("Jolly\n");
        /// @note this is edge case, if n = 1, then Jolly

        if (feof(stdin)){
            break;
        }
    }

    return 0;
}