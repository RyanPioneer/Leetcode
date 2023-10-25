/**
 * Source: tinyurl.com/ykgpb5um
 * Date: 2023/10/25
 * Skill:
 * Runtime: 165 ms, faster than 18.90% of C++ online submissions
 * Memory Usage: 12.00 MB, less than 32.69% of C++ online submissions
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
        vector<vector<int>> dp(sz, vector<int>(sz));
        for (int i = 0; i + 1 < sz; i++) {
            dp[i][i + 1] = min(x, nums[i + 1] - nums[i]);
        }
        for (int len = 4; len <= sz; len += 2) {
            for (int left = 0; left + len <= sz; left++) {
                int right = left + len - 1;
                dp[left][right] = dp[left + 1][right - 1] + min(x, nums[right] - nums[left]);
                for (int mid = left + 1; mid < right; mid += 2) {
                    dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right]);
                }
            }
        }
        return dp[0][sz - 1];
    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
}