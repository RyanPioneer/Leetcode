/**
 * Source: t.ly/Ka-yF
 * Date: 2023/10/14
 * Skill:
 * Runtime: 83 ms, faster than 91.36% of C++ online submissions
 * Memory Usage: 6.49 MB, less than 44.97% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= s.length <= 12
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int maxProduct(string s) {
        int sz = s.length();
        int dp[1 << sz], dp2[sz][sz], res = 1;
        vector<int> nums;
        for (int i = 0; i < (1 << sz); i++)
            dp[i] = -1;

        auto find_palin_num = [&](int num) {
            if (dp[num] != -1)
                return dp[num];
            nums.clear();
            for (int i = 0; i < sz; i++)
                if (((num >> i) & 1) != 0)
                    nums.push_back(i);
            int sz2 = nums.size();
            for (int i = 0; i < sz2; i++)
                dp2[i][i] = 1;
            for (int i = 0; i < sz2 - 1; i++) {
                if (s[nums[i]] == s[nums[i + 1]])
                    dp2[i][i + 1] = 2;
                else
                    dp2[i][i + 1] = 1;
            }
            for (int len = 3; len <= sz2; ++len) {
                for (int i = 0; i + len <= sz2; ++i) {
                    int j = i + len - 1;
                    dp2[i][j] = max(dp2[i][j - 1], dp2[i + 1][j]);
                    if (s[nums[i]] == s[nums[j]])
                        dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - 1] + 2);
                }
            }
            dp[num] = dp2[0][sz2 - 1];
            return dp2[0][sz2 - 1];
        };

        for (int i = 1; i < (1 << sz) - 1; i++) {
            int num = 0;
            for (int j = 0; j < sz; j++) {
                if (((i >> j) & 1) == 0)
                    num += (1 << j);
            }
            res = max(res, find_palin_num(i) * find_palin_num(num));
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}