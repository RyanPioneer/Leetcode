/**
 * Source: https://rb.gy/fps8q
 * Date: 2023/9/17
 * Skill:
 * Runtime: 12 ms, faster than 74.39% of C++ online submissions
 * Memory Usage: 10.12 MB, less than 31.54% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n, m <= 10
 *      There are at most two of each type of topping.
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
using PULL = pair<ULL, ULL>;


class Solution {
    int res = INT32_MAX, sz;
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        sz = toppingCosts.size();
        for (auto base: baseCosts)
            helper(base, 0, toppingCosts, target);
        return res;
    }
    void helper(int total, int idx, vector<int>& toppingCosts, int target) {
        if (abs(total - target) < abs(res - target))
            res = total;
        else if (abs(total - target) == abs(res - target))
            res = min(res, total);
        if (total > target || idx == sz)
            return;
        for (int i = 0; i < 3; i++)
            helper(total + toppingCosts[idx] * i, idx + 1, toppingCosts, target);
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}