/**
 * Source: ibit.ly/un7WT
 * Date: 2023/10/3
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.52 MB, less than 7.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      0 <= n <= 10 ** 9
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
    int dp[10] = {0};
public:
    int countDigitOne(int n) {
        string str = to_string(n);
        return dfs(0, str, true);
    }
    int dfs(int idx, string &str, bool is_edge) {
        if (idx == str.length() - 1) {
            if (!is_edge)
                return 1;
            else
                return str[idx] != '0';
        }
        if (!is_edge && dp[str.length() - idx] != 0)
            return dp[str.length() - idx];
        if (!is_edge) {
            dp[str.length() - idx] = dfs(idx + 1, str, is_edge) * 10 + pow(10, str.length() - idx - 1);
            return dp[str.length() - idx];
        }
        else {
            int res = 0;
            for (int i = 0; i <= str[idx] - '0'; i++) {
                if (i == 0 && idx == 0) {
                    res += dfs(idx + 1, str, false);
                    continue;
                }
                if (i != str[idx] - '0')
                    res += dfs(idx + 1, str, false);
                else
                    res += dfs(idx + 1, str, true);
                if (i == 1) {
                    if (str[idx] != '1')
                        res += pow(10, str.length() - idx - 1);
                    else
                        res += stoi(str.substr(idx + 1)) + 1;
                }
            }
            return res;
        }
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}