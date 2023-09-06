/**
 * Source: https://rb.gy/9cio6
 * Date: 2023/9/6
 * Skill: Math
 * Runtime: 0 ms, faster than 100% of C++ online submissions
 * Memory Usage: 5.94 MB, less than 54.62% of C++ online submissions
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
        ll left = 1, right = 1e6;
        while (left < right) {
            ll mid  = (left + right) / 2;
            ll sum = 4 * ((2 * mid + 1) * (mid * (mid + 1) / 2));
            if (sum < neededApples)
                left = mid + 1;
            else
                right = mid;
        }
        return 8 * left;
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
    ll mid = 4;
    ll res = 4 * (3 * mid + 3 * mid * (mid - 1));
    cout << res << std::endl;
}