#include <iostream>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    if (arr == nullptr) {
        return 1;
    }
    arr[0] = 1;
    int x;
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        int rightIndex = x+1;
        arr[rightIndex] = i+1;
    }

    for (int i =0; i < n; i++) {
        printf("%d ", *(arr+i));
    }
    return 0;
}