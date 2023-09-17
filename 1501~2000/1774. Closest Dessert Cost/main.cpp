/**
 * Source: https://rb.gy/fps8q
 * Date: 2023/9/17
 * Skill:
 * Runtime: 85 ms, faster than 21.83% of C++ online submissions
 * Memory Usage: 10.32 MB, less than 31.27% of C++ online submissions
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
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = INT32_MAX, res_diff = INT32_MAX, sz = toppingCosts.size();
        int num = pow(3, sz);
        for (auto base: baseCosts) {
            for (int i = 0; i < num; ++i) {
                int cost = 0, state = i;
                for (int j = 0; j < sz; ++j) {
                    cost += toppingCosts[j] * (state % 3);
                    state /= 3;
                }
                if (abs(cost + base - target) < res_diff) {
                    res_diff = abs(cost + base - target);
                    res = cost + base;
                } else if (abs(cost + base - target) == res_diff && cost + base < res)
                    res = cost + base;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}