/**
 * Source: tinyurl.com/ykgpb5um
 * Date: 2023/10/26
 * Skill:
 * Runtime: TLE
 * Memory Usage:
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
        int cnt = 0, sz = s1.length();
        for (int i = 0; i < sz; i++) {
            if (s1[i] != s2[i]) cnt++;
        }
        if (cnt % 2 == 1) return -1;

        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(sz, vector<int>(2, sz)));
        function<int(int, int, int)> dfs;
        dfs = [&](int idx, int free, int is_reversed) {
            if (idx == -1) {
                if (free > 0 || is_reversed > 0) return sz;
                return 0;
            }
            int &res = dp[idx][free][is_reversed];
            if (res < sz) return res;
            if ((s1[idx] == s2[idx]) == (is_reversed == 0)) {
                res = dfs(idx - 1, free, 0);
            } else {
                res = min(res, dfs(idx - 1, free, 1) + 1);
                res = min(res, dfs(idx - 1, free + 1, 0) + x);
                if (free > 0) res = min(res, dfs(idx - 1, free - 1, 0));
            }
            return res;
        };
        return dfs(sz - 1, 0, 0);
    }
};


int main() {
    Solution s;
}