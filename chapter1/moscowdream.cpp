#include <iostream>

int main()
{
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    if (a ==0 || b == 0 || c ==0 || n < 3 || (a+b+c) < n)
    {
        printf("NO");
    } else {
        printf("YES");
    }
}