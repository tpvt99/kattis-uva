#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define ll long long int

// This problem is interesting and hard to understand at first.
/*
For sample input 1:
2 3
1 2 3
3 2 1

From 0-1 hour, the first swather is processed at stage 1.
From 1 hour onwards, both swather are processed because first swather is 
now at stage 2, while second swather is at stage 2, so workers can work parally
*/

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int *array = (int *) malloc(sizeof(int) * m * n);

    if (array == nullptr) {
        printf("Error in allocating resources\n");
        return 1;
    }

    ll* timePrevSwatherDone = (ll*) malloc(sizeof(ll) * m);

    if (timePrevSwatherDone == nullptr) {
        printf("Error in allocating resources\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            *(array + i*m + j) = temp;
            //printf("%d:%d\n", i*n + j, temp);
            timePrevSwatherDone[j] = 0ll;
        }
    }

    for (int i = 0; i < n; i++) {
        ll startTime = timePrevSwatherDone[0];
        for (int j = 0; j < m; j++) {
            ll endTime = startTime + (*(array+i*m + j));
            timePrevSwatherDone[j] = endTime;
            //printf("start: %lld, end: %lld\n", startTime, endTime);

            // The starting point of next stage is end of prev state for this swather
            // or end of same stage for prev swather
            if (j == m-1) {
                printf("%lld ", endTime);
                //printf("\n");
                break;
            }
            startTime = max(endTime, timePrevSwatherDone[j+1]);
            //printf("start: %lld\n", startTime);
        }
    }

    return 0;
}