#include <iostream>
#include <stack>

using namespace std;

// All bit are 0-based index

#define isOn(S, j) (S & (1 << j)) // If bit j is set
#define setBit(S, j) (S |= (1<<j)) // Set bit j

void printSet(int vS) {
    printf("S = %2d = ", vS);
    std::stack<int> st;
    while (vS)
        st.push(vS%2), vS /= 2;
    while (!st.empty())
        printf("%d", st.top()), st.pop();

    printf("\n");
}

int main() {
    int S, T;
    printf("1. Representation (all indexing are 0-base and counted from right)");
    S = 34; printSet(S);
}