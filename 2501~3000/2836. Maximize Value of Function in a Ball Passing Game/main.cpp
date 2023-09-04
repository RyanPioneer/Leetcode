/**
 * Source: https://rb.gy/i9jtc
 * Date: 2023/9/4
 * Skill:
 * Runtime: 742 ms, faster than 44.17% of C++ online submissions
 * Memory Usage: 270.21 MB, less than 45.92% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <set>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int bit_num = 0, n = receiver.size(), pos = 0;
        ll tmp = k, res = 0;
        vector<int> bit_pos;
        while (tmp > 0) {
            if ((tmp & 1) != 0)
                bit_pos.push_back(pos);
            pos++;
            bit_num++;
            tmp >>= 1;
        }
        vector<vector<ll>> dp(n, vector<ll>(bit_num + 1, 0));
        vector<vector<int>> next_pos(n, vector<int>(bit_num + 1, 0));
        for (int i = 0; i < n; i++) {
            next_pos[i][0] = receiver[i];
            dp[i][0] = receiver[i];
        }
        for (int i = 1; i <= bit_num; i++)
            for (int j = 0; j < n; j++) {
                next_pos[j][i] = next_pos[next_pos[j][i - 1]][i - 1];
                dp[j][i] = dp[j][i - 1] + dp[next_pos[j][i - 1]][i - 1];
            }
        for (int i = 0; i < n; i++) {
            ll num = 0, cur = i;
            for (auto j: bit_pos) {
                num += dp[cur][j];
                cur = next_pos[cur][j];
            }
            res = max(res, num + i);
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
    vector<int> v1{1,2,1,2,1,2}, v2{2,1,1,2,2,1};
}