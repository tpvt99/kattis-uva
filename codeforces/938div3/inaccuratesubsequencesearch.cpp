#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

// sliding window technique
// My first solution fails because of extra number in a window
// E.g., [9, 9, 7, 8, 10], then pair contains only one 9-9 pair

void solve_slidingWindow() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arrayA (n, 0);
    multiset<int> arrayB;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arrayA[i] = temp;
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        arrayB.insert(temp);
    }

    // Sliding with window = m, from arrayA first
    multiset<int> pair;
    int count = 0;
    for (int i = 0; i < m; i++){
        if (arrayB.find(arrayA[i]) != arrayB.end()) {
            // We are able to find a pair, adding into pair
            pair.insert(arrayA[i]);
            arrayB.erase(arrayA[i]);
            count++;
        }
    }
    int result = 0;
    // First window is done, if count >= k then we have 1 result
    if (count >= k)
        result += 1;
    // Now we continue till end
    for (int i = m; i < n; i++) {
        // Need to remove arrayA[i-m] (when i =m , then A[i-m]=A[0], which is front element of sliding window)
        // , and if arrayA[i-m] in pair, need to remove
        // and deduct count
        cout << "Window starts " << arrayA[i-m] << " ends " << arrayA[i-1] << " has count: " << count << endl;
        if (pair.find(arrayA[i-m]) != pair.end()) {
            pair.erase(arrayA[i-m]);
            arrayB.insert(arrayA[i-m]);
            count--;
        }

        if (arrayB.find(arrayA[i]) != arrayB.end()) {
            pair.insert(arrayA[i]);
            arrayB.erase(arrayA[i]);
            count++;
        }
        if (count >= k)
            result += 1;
    }
    cout << result << endl;
}


// Working solution with an extra array to protect more than one pair
void solve_slidingWindow2() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arrayA (n, 0);
    multiset<int> arrayB;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arrayA[i] = temp;
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        arrayB.insert(temp);
    }

    // Sliding with window = m, from arrayA first
    multiset<int> pair;
    multiset<int> extra;
    for (int i = 0; i < m; i++){
        if (arrayB.find(arrayA[i]) != arrayB.end()) {
            // We are able to find a pair, adding into pair
            pair.insert(arrayA[i]);
            arrayB.erase(arrayB.find(arrayA[i]));
        } else {
            // Only add if no pair or if already exists a pair
            extra.insert(arrayA[i]);
        }
    }
    int result = 0;
    // First window is done, if count >= k then we have 1 result
    if (pair.size() >= k)
        result += 1;
    // Now we continue till end
    for (int i = m; i < n; i++) {
        // Need to remove arrayA[i-m] (when i =m , then A[i-m]=A[0], which is front element of sliding window)
        // , and if arrayA[i-m] in pair, need to remove
        // and deduct count
        if (extra.find(arrayA[i-m]) != extra.end()) {
            extra.erase(extra.find(arrayA[i-m]));
        } else if (pair.find(arrayA[i-m]) != pair.end()) {
            pair.erase(pair.find(arrayA[i-m]));
            arrayB.insert(arrayA[i-m]);
        }

        if (arrayB.find(arrayA[i]) != arrayB.end()) {
            pair.insert(arrayA[i]);
            arrayB.erase(arrayB.find(arrayA[i]));
        } else {
            extra.insert(arrayA[i]);
        }
        if (pair.size() >= k)
            result += 1;
    }
    cout << result << endl;
}

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        solve_slidingWindow2();
    }

    return 0;
}