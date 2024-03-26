#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> v{10,20,30,30,30,40,50,50,100};

    vector<int>::iterator it = lower_bound(v.begin(), v.end(), -1);

    if (it == v.end()) {
        cout << "Iterator is end" << endl;
    } else if (it == v.begin()) {
        cout << "Iterator is begin" << endl;
        cout << *it << endl;
    }

    it = lower_bound(v.begin(), v.end(), 101);

    if (it == v.end()) {
        cout << "Iterator is end" << endl;
        cout << *it << endl;
        cout << *(it - 1) << endl;
    } else if (it == v.begin()) {
        cout << "Iterator is begin" << endl;
    }

    return 0;
}