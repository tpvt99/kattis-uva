#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// Try to generate permutation

int dfs(vector<int>& v, int index, vector<bool>& chosen, vector<int>& result, 
    vector<int>& model, int k) {
    if (index == v.size())
    {
        int count = 0;
        for (int i = 0; i < result.size(); i++)
        {
            if (result[i] == model[i])
            {
                count++;
            }
            else {
                count = 0;
            }
            std::cout << result[i] << " ";
            if (count == k)
            {
                std::cout << " | OKAY" << std::endl;
                return 1;
            }
        }
        std::cout << std::endl;
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        // Choosing this index
        if (!chosen[i]){
            result.emplace_back(v[i]);
            chosen[i] = true;

            if (v[i] == model[index])
                sum += dfs(v, index+1, chosen, result, model, k);
            else
                sum += dfs(v, index+1, chosen, result, model, k);


            result.pop_back();
            chosen[i] = false;
        }
    }
    return sum;
}

int main()
{
    int x;
    scanf("%d", &x);
    while (x-- > 0)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);

        vector<int> arrayA (n, 0);
        vector<int> arrayB (m, 0);
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            arrayA[i] = temp;
        }
        for (int i = 0; i < m; i++)
        {
            int temp;
            scanf("%d", &temp);
            arrayB[i] = temp;
        }
        vector<bool> chosen(m, false);
        vector<int> result;
        int count = dfs(arrayB, 0, chosen, result, arrayA, k);
        printf("Result: %d\n", count);
    }

    return 0;
}