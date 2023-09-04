/**
 * Source: https://rb.gy/0bhl6
 * Date: 2023/9/4
 * Skill:
 * Runtime: 8 ms, faster than 77.51% of C++ online submissions
 * Memory Usage: 6 MB, less than 52.47% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
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
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        ll res = 0;
        for (int i = 0; i <= total / cost1; i++)
            res += (total - i * cost1) / cost2 + 1;
        return res;
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
    vector<int> v1{1,2,1,2,1,2}, v2{2,1,1,2,2,1};
}