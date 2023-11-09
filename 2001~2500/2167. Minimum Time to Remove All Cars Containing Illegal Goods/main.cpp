/**
 * Source: t.ly/zrw0E
 * Date: 2023/11/9
 * Skill:
 * Runtime: 160 ms, faster than 60.84% of C++ online submissions
 * Memory Usage: 63.46 MB, less than 54.82% of C++ online submissions
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

const int MX = 2 * 1e5 + 2;

class Solution {
public:
    int minimumTime(string s) {
        int len = s.length(), res = s.length(), dp[MX][3] = {0}; // 0: from left 1: anywhere 2: from right
        vector<int> pos;
        pos.push_back(0);
        for (int i = 0; i < len; i++) {
            if (s[i] == '1') {
                pos.push_back(i + 1);
            }
        }
        int sz = pos.size();
        for (int i = 1; i < sz; i++) {
            dp[i][0] = dp[i - 1][0] + pos[i] - pos[i - 1];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 2;
        }
        res = min(dp[sz - 1][0], dp[sz - 1][1]);
        pos.push_back(len + 1);
        for (int i = sz - 1; i > 0; i--) {
            dp[i][1] = min(dp[i + 1][1], dp[i + 1][2]) + 2;
            dp[i][2] = dp[i + 1][2] + pos[i + 1] - pos[i];
            res = min(res, min(dp[i - 1][0], dp[i - 1][1]) + min(dp[i][1], dp[i][2]));
        }
        return res;
    }
};


int main() {
    Solution s;
    int res = s.minimumTime("0010");
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}