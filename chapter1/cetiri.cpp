#include <iostream>

int main() {
    int a,b,c;

    scanf("%d%d%d", &a, &b, &c);
    // Sort first
    int low, mid, high;
    if (a <= b) {
        if (c <= a) {
            low = c;
            mid = a;
            high = b;
        }
        else if (c <= b){
            low = a;
            mid = c;
            high = b; 
        } else if (c >= b) {
            low = a;
            mid = b;
            high = c;
        }
    } else {
        if (c <= b) {
            low = c;
            mid = b;
            high = a;
        } else if (c <= a) {
            low = b;
            mid = c;
            high = a;
        } else if (c >= a) {
            low = b;
            mid = a;
            high = c;
        }
    }

    int dist1 = mid-low;
    int dist2 = high-mid;
    if (dist1 == dist2) {
        printf("%d\n", high+dist1);
    } else if (dist1 < dist2) {
        printf("%d\n", mid + dist1);
    } else if (dist1 > dist2) {
        printf("%d\n", low+dist2);
    }

    return 0;
}