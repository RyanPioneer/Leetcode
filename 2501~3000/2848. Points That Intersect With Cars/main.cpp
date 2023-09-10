/**
 * Source: https://rb.gy/8sfzy
 * Date: 2023/9/10
 * Skill:
 * Runtime: 15 ms, faster than 75.00% of C++ online submissions
 * Memory Usage: 25.07 MB, less than 50.00% of C++ online submissions
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
        sort(nums.begin(), nums.end());
        int res = 0, left = -1, right = -2;
        for (auto n: nums) {
            if (n[0] <= right)
                right = max(right, n[1]);
            else {
                res += right - left + 1;
                left = n[0];
                right = n[1];
            }
        }
        return res + right - left + 1;
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