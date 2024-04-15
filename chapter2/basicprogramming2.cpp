#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <vector>

template<typename T>
bool sortIncreasing(T x, T y) {
    return (x < y) ? 1 : 0;
}

int main() {
    int N, t;
    scanf("%d%d", &N, &t);

    std::vector<int> array(N);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        array[i] = temp;
    }

    switch (t) {
        case 1: {
            std::set<int> diff;
            bool is7777 = false;
            for (int i = 0; i < N; i++) {
                if (diff.find(7777-array[i]) != diff.end()) {
                    printf("Yes\n");
                    is7777 = true;
                    break;
                }
                diff.insert(array[i]);
            }
            if (! is7777)
                printf("No\n");
            break;
        }
        case 2: {
            std::sort(array.begin(), array.end(), sortIncreasing<int>);
            bool duplicate = false;
            for (int i = 0; i < N-1; i++) {
                if (array[i] == array[i+1]) {
                    printf("Contains duplicate\n");
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate)
                printf("Unique\n");
            break;
        }
        case 3: {
            int count = 0;
            int majority = 0;
            for (int i = 0; i < N; i++) {
                if (count == 0) {
                    majority = array[i];
                    count++;
                } else if (array[i] != majority) {
                    count--;
                } else if (array[i] == majority) {
                    count++;
                }
            }
            // Second loop to verify
            count =0;
            for (int i =0; i < N; i++) {
                if (array[i] == majority)
                    count++;
            }
            if (count > N/2)
                printf("%d\n", majority);
            else
                printf("-1\n");
            break;
        }
        case 4: {
            std::sort(array.begin(), array.end(), sortIncreasing<int>);
            if (N % 2 == 0) {
                printf("%d %d\n", array[N/2-1], array[N/2]);
            } else {
                printf("%d\n", array[N/2]);
            }
            break;
        } 
        case 5: {
            std::sort(array.begin(), array.end(), sortIncreasing<int>);
            bool printSpace = false;
            for (int i = 0; i < N; i++) {
                if (array[i] >= 100 && array[i] <= 999) {
                    if (printSpace)
                        printf(" ");
                    printf("%d", array[i]);
                    printSpace = true;
                }
            }
            break;
        }
    }
}