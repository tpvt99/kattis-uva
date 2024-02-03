#include <iostream>
#include <cstring>

int main()
{
    const char *str1 = "OCT";
    const char *str2 = "DEC";
    char month[4];
    int day;
    scanf("%[^ ]%d\n", month, &day);
    if ((std::strcmp(month, str1) == 0 && day == 31) || (std::strcmp(month, str2) == 0 && day == 25))
    {
        printf("yup");
    } else 
    {
        printf("nope");
    }
    return 0;
}