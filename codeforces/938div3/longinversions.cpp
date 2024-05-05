#include <iostream>
#include <vector>

using namespace std;


// Solution after checking editorial hints
// Gives TLE because I maintain inversionCounter to count

void solve_greedy() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    //cout << "------------------------------" << endl;
    //cout << "String is: " << s << endl;

    for (int k = n; k > 0; k--) {
        vector<int> inversionCounter(n, 0);
        //cout << "k is: " << k << endl;

        int startIndex = 0;
        while (startIndex < n) {
            // If it is still range startIndex + k
            //cout << "StartIndex " << startIndex << endl;
            if (startIndex + k <= n) {
                // Check if s[i] is '0' based on s[i] and inversionCounter
                //cout << "In range Checking: " << (s[startIndex] == '0') <<  
                    //" " << (inversionCounter[startIndex] % 2 == 0) <<
                    //" " << (s[startIndex] == '1') << 
                    //" " << (inversionCounter[startIndex] % 2 == 1) << endl;
                if ((s[startIndex] == '0' && (inversionCounter[startIndex] % 2 == 0)) || 
                    (s[startIndex] == '1' && inversionCounter[startIndex] % 2 == 1)) {
                    //cout << "Inverting from " << startIndex << endl;
                    // Starting to flip from i till i+k
                    for (int j = startIndex; j < startIndex+k; j++) {
                        inversionCounter[j]++;
                    }
                }
                startIndex += 1;
            // If not, then we should not go further
            } else {
                break;
            }
        }
        // Index 0 to startIndex-1 is already 1, now just check from startIndex till end
        bool isAllOne = true;
        for (int j = 0; j < n; j++) {
            if ((s[j] == '0' && inversionCounter[j] % 2 == 0) || 
                (s[j] == '1' && inversionCounter[j] % 2 == 1)) {
                    isAllOne = false;
                    break;
                }

        }
        if (isAllOne) {
            cout << k << endl;
            return;
        }
    }
}

void solve_greedy_optimizeWithArray() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    //cout << "------------------------------" << endl;
    //cout << "String is: " << s << endl;


    for (int k = n; k > 0; k--) {
        // endCounter[i] is how much we invert s[i] already
        //cout << "K is: " << k << endl;
        vector<int> end(n+1, 0);
        int cnt = 0;

        // Without inversionCounter, we have to transform s[i] while traversing
        vector<int> t(n);
        for (int i = 0; i < n; i++)
            t[i] = s[i] - '0';

        int startIndex = 0;
        for (int startIndex = 0; startIndex < n; startIndex++){
            // If it is still range startIndex + k
            cnt -= end[startIndex];
            //cout << "StartIndex " << startIndex << " cnt: " << cnt << " before: "
             //<< t[startIndex];
            t[startIndex] ^= (cnt % 2);
            //cout << " after: " << t[startIndex] << endl;
            if (startIndex + k <= n) {
                //cout << "In range" << endl;
                // Check if s[i] is '0'
                if (t[startIndex] == 0) {
                    // Convert to 1. Add counter
                    t[startIndex] = 1;
                    cnt += 1;
                    // It needs to be startIndex+k, which surpass the last 
                    // number that it is inverted
                    end[startIndex+k]+= 1;
                    //cout << "Converting cnt: " << cnt << " end of " << startIndex+k << " " 
                    //<< end[startIndex+k] << endl;
                }
            // if not in range, and it is 0, we cannot change any more
            // can break here
            }
        }
        // Index 0 to startIndex-1 is already 1, now just check from startIndex till end
        bool isAllOne = true;
        for (int j = 0; j < n; j++) {
            if (t[j] == 0){
                isAllOne = false;
                break;
            }
        }
        if (isAllOne) {
            cout << k << endl;
            return;
        }
    }
}

int main() {
    int x;
    cin >> x;
    while (x--) {
        solve_greedy_optimizeWithArray();
    }
}