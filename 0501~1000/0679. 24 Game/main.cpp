/**
 * Source: is.gd/b05j0a
 * Date: 2023/12/1
 * Skill:
 * Ref:
 * Runtime: 42 ms, faster than 22.22% of C++ online submissions
 * Memory Usage: 21.39 MB, less than 18.11% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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
const int len = 4;


class Solution {
    unordered_set<double> dp[len][len];
public:
    bool judgePoint24(vector<int>& cards) {
        return permute(cards, 0);
    }
    bool permute(vector<int>& cards, int idx) {
        if (idx == 4) return helper(cards);
        for (int i = idx; i < len; i++) {
            swap(cards[idx], cards[i]);
            if (permute(cards, idx + 1)) return true;
            swap(cards[idx], cards[i]);
        }
        return false;
    }
    bool helper(vector<int>& cards) {
        for (int i = 0; i < len; i++) {
            dp[i][i].clear();
            dp[i][i].insert(cards[i]);
        }
        for (int i = 2; i <= len; i++) {
            for (int j = 0; j + i <= len; j++) {
                int right = j + i - 1;
                dp[j][right].clear();
                for (int k = j; k < right; k++) {
                    for (auto &l: dp[j][k]) {
                        for (auto &m: dp[k + 1][right]) {
                            unordered_set<double> res = calculate(l, m);
                            for (auto &n: res) dp[j][right].insert(n);
                        }
                    }
                }
            }
        }
        for (auto &i: dp[0][len - 1]) {
            if (abs(i - 24.0) < 0.001) return true;
        }
        return false;
    }
    unordered_set<double> calculate(double a, double b) {
        unordered_set<double> ans;
        ans.insert(a + b);
        ans.insert(a - b);
        ans.insert(a * b);
        if (b != 0.0) ans.insert(a / b);
        return ans;
    }
};

// int main() {
//     Solution s;
//     vector<int> nums{4,1,8,7};
//     bool res = s.judgePoint24(nums);
//     vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
//     ll dp[2][2][4] = {0};
//     dp[1][1][1] = 3;
//     memset(dp, 0, sizeof(dp));
// }