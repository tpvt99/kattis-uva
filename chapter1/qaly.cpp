#include <iostream>

int main()
{
    int n;
    scanf("%d", &n);
    float accum = 0;
    while (n-- > 0)
    {
        float a,b;
        scanf("%f %f", &a, &b);
        accum += a*b;
    }
    printf("%.3f", accum);
    return 0;
}