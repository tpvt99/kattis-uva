#include <iostream>

int main()
{
    int x;
    int sum = 0;
    int count = 0;
    int i = 0;
    scanf("%d", &x);
    scanf("%d", &count);
    while (scanf("%d", &i) != EOF)
    {
        sum += i;
    }
    printf("%d", x * count - sum + x);
    return 0;
}