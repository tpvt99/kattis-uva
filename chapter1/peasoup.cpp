#include <iostream>
#include <cstring>

void strip_extra_space(char *str) {
    int i, x=0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i]) || (i > 0 && !isspace(str[i-1]))){
            str[x++] = str[i];
        }
    }
    str[x] = '\0';
}

int main() {
    int n;
    scanf("%d", &n);

    char firstRestaurant[101] = "\0";
    int validRestaurant = 0;
    for (int i = 0; i < n; i++) {
        int numMenus;
        scanf("%d\n", &numMenus);
        char name[101];
        scanf("%100[ a-z]\n", name);

        char menu[101];
        bool hasPancakes = false;
        bool hasPeaSoup = false;
        //printf("num menu %d rest name: %s\n, ", numMenus, name);
        while (scanf("%100[ a-z]\n", menu) > 0) {
            //strip_extra_space(menu);
            //printf("menu %s\n, ", menu);
            if (std::strcmp(menu, "pancakes") == 0) {
                hasPancakes = true;
            }
            if (std::strcmp(menu, "pea soup") == 0) {
                hasPeaSoup = true;
            }
            //if (std::strstr(menu, "paa soup") != nullptr) {
                //hasPeaSoup = true;
            //}
        }
        if (hasPancakes && hasPeaSoup) {
            if (std::strlen(firstRestaurant) == 0) {
                std::strcpy(firstRestaurant, name);
            }
            //printf("this %s has both\n", menu);
            validRestaurant++;
        }
    }
    if (validRestaurant == 0)
        printf("Anywhere is fine I guess\n");
    else
        printf("%s", firstRestaurant);

    return 0;
}