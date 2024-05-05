#include <stdio.h>
#include <map>

int main()
{
    int n;
    scanf("%d", &n);
    while (n-- > 0)
    {
        int x, c, d;
        scanf("%d%d%d", &x, &c, &d);
        std::map<int, int> matrix;
        int totalNumber = x*x;
        int minNum = INT_MAX;
        while (totalNumber-- > 0)
        {
            int temp;
            scanf("%d", &temp);
            matrix[temp] += 1;
            minNum = std::min(temp, minNum);
        }
        // I can generate line by line beginning with a00
        bool progressive = true;
        for (int row = 0; row < x; row++)
        {
            int next = minNum;
            for (int col = 0; col < x; col++)
            {
                if (matrix.find(next) == matrix.end())
                {
                    progressive = false;
                    break;
                }
                else
                matrix[next]-=1;
                if (matrix[next] == 0)
                    matrix.erase(next);
                next += d;
            }
            if (! progressive)
                break;
            minNum += c;
        }
        if (progressive)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}