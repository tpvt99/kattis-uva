#include <iostream>

int main() {
    int A, t;
    scanf("%d%d", &A, &t);
    int *arr = (int *) malloc(sizeof(int) * A);
    for (int i = 0; i < A; i++) {
        scanf("%d", arr+i);
    }

    switch(t) {
        case 1:
            printf("7\n");
            break;
        case 2:
            if (arr[0] > arr[1]) {
                printf("Bigger");
            } else if (arr[0] == arr[1]) {
                printf("Equal");
            } else {
                printf("Smaller");
            }
            break;
        case 3:{
            int biggest = std::max(arr[0], std::max(arr[1], arr[2]));
            if (arr[0] == biggest){
                printf("%d\n", std::max(arr[1], arr[2]));
            } else if (arr[1] == biggest) {
                printf("%d\n", std::max(arr[0], arr[2]));
            } else if (arr[2] == biggest) {
                printf("%d\n", std::max(arr[0], arr[1]));
            }
            break;
        }
        case 4:{
            long long int sum = 0;
            for (int i = 0; i < A; i++) {
                sum += arr[i];
            }
            printf("%lld\n", sum);
            break;
        }
        case 5:{
            long long int sum = 0;
            for (int i = 0; i < A; i++) {
                sum += ((arr[i] % 2) == 0) ? arr[i] : 0;
            }
            printf("%lld\n", sum);
            break;
        }
        case 6:{
            char *str = (char*) malloc(sizeof(char) * (A+1));
            for (int i = 0; i < A; i++) {
                int m = (arr[i] % 26);
                str[i] = m + 'a';
            }
            str[A] = '\0';
            printf("%s\n", str);
            break;
        }
        case 7:{
            bool visited[A] = {false};
            int i = 0;
            while (visited[i] == false) {
                visited[i] = true;
                i = arr[i];
                if (i >= A || i < 0){
                    printf("Out");
                    break;
                } else if (i == A-1) {
                    printf("Done");
                    break;
                }
            }
            if (visited[i] == true){
                printf("Cyclic");
            }
            break;
        }
    }

    return 0;
}