#include <iostream>
#include <stack>

using namespace std;

// All bit are 0-based index

#define isOn(S, j) (S & (1 << j)) // If bit j is set
#define setBit(S, j) (S |= (1<<j)) // Set bit j
#define clearBit(S, j) (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S) (S & -S)
#define setAll(S, n) (!(S&(S-1)))

#define isPowerOfTwo(S) (S == (S & -S))
#define turnOffLastBit(S) (S&(S-1)) // last bit is first 1 from right-to-left
#define turnOnLastZero(S) (S|(S+1))// last 0 is first 0 from right-to-left

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
    printf("1. Representation (all indexing are 0-base and counted from right)\n");
    S = 34; printSet(S);

    printf("2. Multiply S by 2, then divide S by 4 (2x2), then by 2\n");
    S = 34; printSet(S);
    S = S << 1; printSet(S);
    S = S >> 2; printSet(S);
    S = S >> 1; printSet(S);

    printf("3. Set/turn on the 3rd item of the set\n");
    S = 34; printSet(S);
    setBit(S, 3); printSet(S);

    printf("4. Check if the 3-rd and then 2-nd im of the set is on?\n");
    S = 42; printSet(S);
    T = isOn(S, 3); printf("T = %d, %s\n", T, T ? "ON" : "OFF");
    T = isOn(S, 2); printf("T = %d, %s\n", T, T ? "ON" : "OFF");

    printf("5. Clear/tunr off the 1-st item of the set\n");
    S = 42; printSet(S);
    clearBit(S, 1); printSet(S);

    printf("6. Toggle the 2nd item and then 3rd item of the set\n");
    S = 40; printSet(S);
    toggleBit(S, 2); printSet(S);
    toggleBit(S, 3); printSet(S);

    printf("7. Check the first bit from right that is on\n");
    S = 40; printSet(S);
    T = lowBit(S); printf("T = %d (this is always a power of 2)\n", T);
    S = 52; printSet(S);
    T = lowBit(S); printf("T = %d (this is always a power of 2)\n", T);
    printf("\n");

    printf("8. Turn on all bits in a set of size n=6\n");
    setAll(S, 6); printSet(S);
    printf("\n");

    printf("is %d power of two? %d\n", 9, isPowerOfTwo(9));
    printf("is %d power of two? %d\n", 8, isPowerOfTwo(8));
    printf("is %d power of two? %d\n", 7, isPowerOfTwo(7));
}