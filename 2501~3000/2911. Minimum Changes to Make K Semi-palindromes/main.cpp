/**
 * Source: tinyurl.com/yuy673by
 * Date: 2023/10/25
 * Skill:
 * Runtime: 124 ms, faster than 89.01% of C++ online submissions
 * Memory Usage: 33.12 MB, less than 51.65% of C++ online submissions
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

const int MX = 201;
vector<vector<int>> divisors(MX);
int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i * 2; j < MX; j += i) {
            divisors[j].push_back(i);
        }
    }
    return 0;
}();

class Solution {
    int get_modify(string s) {
        int sz = s.length(), res = s.length();
        for (auto len: divisors[sz]) {
            int cnt = 0;
            for (int i0 = 0; i0 < len; i0++) {
                for (int i = i0, j = sz - len + i0; i < j; i += len, j -= len) {
                    cnt += (s[i] != s[j]);
                }
            }
            res = min(res, cnt);
        }
        return res;
    }
public:
    int minimumChanges(string s, int k) {
        int sz = s.length();
        vector<vector<int>> modify(sz, vector<int>(sz));
        for (int left = 0; left < sz - 1; left++) {
            for (int right = left + 1; right < sz; right++) {
                modify[left][right] = get_modify(s.substr(left, right - left + 1));
            }
        }
        vector<vector<int>> dp(k, vector<int>(sz, sz + 1));
        function<int(int, int)> dfs = [&](int time, int right) {
            if (time == 0)
                return modify[0][right];
            int &res = dp[time][right];
            if (res <= sz)
                return res;
            for (int left = time * 2; left < right; left++) {
                res = min(res, dfs(time - 1, left - 1) + modify[left][right]);
            }
            return res;
        };
        return dfs(k - 1, sz - 1);
    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
}