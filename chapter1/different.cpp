#include <iostream>

int main()
{
    //unsigned long long a, b;
    //while(scanf("%llu %llu", &a, &b) != EOF)
    //{
        //if (a > b)
            //printf("%llu\n", a-b);
        //else
            //printf("%llu\n", b-a);
    //}
    long long int a, b;
    while (scanf("%lld %lld", &a, &b) != EOF)
    {
        printf("%lld\n", std::abs(a-b));
    }
    return 0;
}