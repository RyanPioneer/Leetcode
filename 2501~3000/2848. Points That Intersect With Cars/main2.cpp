/**
 * Source: https://rb.gy/8sfzy
 * Date: 2023/9/10
 * Skill:
 * Runtime: 11 ms, faster than 100% of C++ online submissions
 * Memory Usage: 25.44 MB, less than 12.50% of C++ online submissions
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

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> diff(102, 0);
        for (auto n: nums) {
            diff[n[0]]++;
            diff[n[1] + 1]--;
        }
        int res = 0, cur = 0;
        for (int i = 1; i <= 100; ++i) {
            cur += diff[i];
            res += (cur > 0);
        }
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
}