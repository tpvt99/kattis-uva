#include <iostream>
#include <cstring>

#define MAX_SIZE 10

int main()
{
    char *s = (char *) std::malloc(MAX_SIZE);
    if (s == nullptr)
    {
        printf("No memory\n");
        return 1;
    }
    // Not limiting to num characters, not reading new line. but total chars must be 9 only
    scanf("%[^\n]", s); 
    // Safer scanf("9%[^\n]", s) if max_size is 10
    printf("Thank you, %s, and farewell!", s);
    return 0;
}