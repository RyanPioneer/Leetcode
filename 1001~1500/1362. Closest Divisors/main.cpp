/**
 * Source: https://rb.gy/lbigh
 * Date: 2023/8/30
 * Skill:
 * Runtime: 3 ms, faster than 97.21% of C++ online submissions
 * Memory Usage: 6.14 MB, less than 49.80% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= num <= 10^9
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define ll long long
// using ll = long long;


class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> result;
        for (int i = sqrt(num + 2); i > 0; i--) {
            if ((num + 1) % i == 0) {
                vector<int> res{i, (num + 1) / i};
                return res;
            }
            if ((num + 2) % i == 0) {
                vector<int> res{i, (num + 2) / i};
                return res;
            }
        }
        return result;
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
    Solution s;
    vector<int> tasks{1,2,3,1};
}