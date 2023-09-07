/**
 * Source: https://rb.gy/2dalj
 * Date: 2023/9/7
 * Skill:
 * Runtime: 908 ms, faster than 33.00% of C++ online submissions
 * Memory Usage: 347.77 MB, less than 21.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums[i] <= 100
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
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> presum(nums.size() + 1, vector<int>(101, 0));
        presum[1][nums[0]] = 1;
        for (int i = 1; i < nums.size(); i++)
            for (int j = 1; j <= 100; j++)
                presum[i + 1][j] = presum[i][j] + (nums[i] == j);
        vector<int> res;
        for (auto q: queries) {
            int l = q[0], r = q[1];
            if (l == r)
                res.push_back(-1);
            int a = 0, diff = INT32_MAX;
            for (int i = 1; i <= 100; i++) {
                if (presum[r + 1][i] - presum[l][i] > 0) {
                    if (a == 0)
                        a = i;
                    else {
                        diff = min(diff, i - a);
                        a = i;
                    }
                }
            }
            if (diff == INT32_MAX)
                res.push_back(-1);
            else
                res.push_back(diff);
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
    vector<int> row{1,3,0,2,4};
    int res = s.bestRotation(row);
    cout << res << endl;
}