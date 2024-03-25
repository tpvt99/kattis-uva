#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>

struct team {
    int id;
    int solved;
    int penalty;
};

bool icpc_cmp(const team& a, const team& b) {
    // First criteria is number of solved problems
    if (a.solved != b.solved)
        return a.solved > b.solved;
    
    // Second criteria is penalty if solved problems are same
    if (a.penalty != b.penalty)
        return a.penalty < b.penalty;

    // If solved problems and penalty are same, then sort by ID
    return a.id < b.id;
}

int main() {
    int arr[] = {10, 2, 8, 7, 1};
    std::vector<int> v{10,2,9,5,8};

    // Sorting a dynamic array (vector)
    printf("Original order of vector:\n");
    for (auto val: v) {
        printf("%d ", val);
    }
    printf("\n");

    printf("After sorting vector:\n");
    std::sort(v.begin(), v.end());
    for (auto val: v) {
        printf("%d ", val);
    }
    printf("\n");

    printf("After reverse sorting vector:\n");
    std::sort(v.rbegin(), v.rend());
    for (auto val: v) {
        printf("%d ", val);
    }
    printf("\n");

    // Sorting a fixed-size array
    printf("Original order of array:\n");
    for (auto val: arr) {
        printf("%d ", val);
    }
    printf("\n");

    std::sort(arr, arr+5);
    printf("After sorting array:\n");
    for (auto val: arr) {
        printf("%d ", val);
    }
    printf("\n");

    std::reverse(arr, arr+5);
    printf("After reverse sorting array:\n");
    for (auto val: arr) {
        printf("%d ", val);
    }
    printf("\n");

    // multi-field sorting
    team nus[4] = {{1, 1, 10},
                    {2, 3, 60},
                    {3, 1, 20},
                    {4, 3, 60}};

    // Without sorting:
    printf("Before sorting:\n");
    for (const auto& t : nus)
        printf("id: %d, solved: %d, penalty: %d\n", t.id, t.solved, t.penalty);

    std::sort(nus, nus+4, icpc_cmp);
    printf("After sorting:\n");
    // Without sorting:
    for (const auto& t : nus)
        printf("id: %d, solved: %d, penalty: %d\n", t.id, t.solved, t.penalty);

    // Standard sorting using tuple

    using state = std::tuple<int, std::string, std::string>;
    state a = {7, "alex", "zeck"};
    state b = {1, "azek", "xavier"};
    state c = {5, "how", "bayfront"};
    state d = {7, "put", "fly"};
    std::vector<state> states{a, b, c, d};

    // Without sorting:
    printf("Before sorting:\n");
    for (const auto& [value, name1, name2]: states) {
        printf("value: %d, name1: %s, name2: %s\n", value, name1.c_str(), name2.c_str());
    }
    
    // After sorting
    std::sort(states.begin(), states.end());
    printf("After sorting:\n");
    for (const auto& [value, name1, name2]: states) {
        printf("value: %d, name1: %s, name2: %s\n", value, name1.c_str(), name2.c_str());
    }

}