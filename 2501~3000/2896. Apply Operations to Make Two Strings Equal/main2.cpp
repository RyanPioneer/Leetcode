/**
 * Source: tinyurl.com/ykgpb5um
 * Date: 2023/10/26
 * Skill:
 * Runtime: 8 ms, faster than 77.72% of C++ online submissions
 * Memory Usage: 7.63 MB, less than 79.55% of C++ online submissions
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
#include <bitset>
#include <functional>
#include <list>

using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> nums;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                nums.push_back(i);
            }
        }
        int sz = nums.size();
        if (sz == 0) return 0;
        if (sz % 2 == 1) return -1;
        vector<double> dp(sz, -1);
        function<double(int)> dfs;
        dfs = [&](int idx) -> double {
            if (idx == -1)
                return 0;
            double &res = dp[idx];
            if (res != -1)
                return res;
            res = dfs(idx - 1) + (double) x / 2;
            if (idx > 0)
                res = min(res, dfs(idx - 2) + nums[idx] - nums[idx - 1]);
            return res;
        };
        return dfs(sz - 1);
    }
};


int main() {
    Solution s;
}