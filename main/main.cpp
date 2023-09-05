/**
 * Source: https://rb.gy/2hwwx
 * Date: 2023/9/5
 * Skill:
 * Runtime: 123 ms, faster than 82.44% of C++ online submissions
 * Memory Usage: 72.95 MB, less than 38.55% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    long long minimumPerimeter(long long neededApples) {

    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    std::multiset<int> mySet = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    // Create a reverse iterator to iterate from the end (highest values) to the beginning.
    std::multiset<int>::reverse_iterator rit = mySet.rbegin();

    // Print the top 4 highest values.
    for (int i = 0; i < 4 && rit != mySet.rend(); ++i, ++rit) {
        std::cout << *rit << " ";
    }
}