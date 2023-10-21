/**
 * Source: tinyurl.com/yl5aa9nd
 * Date: 2023/10/21
 * Skill:
 * Runtime: 202 ms, faster than 84.49% of C++ online submissions
 * Memory Usage: 120.17 MB, less than 75.92% of C++ online submissions
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        int res = INT32_MIN;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && i - q.front() > k)
                q.pop_front();
            dp[i] = nums[i] + (q.empty() ? 0 : dp[q.front()]);
            res = max(res, dp[i]);
            while (!q.empty() && dp[i] >= dp[q.back()])
                q.pop_back();
            if (dp[i] > 0)
                q.push_back(i);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{5,4,6};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}