/**
 * Source: https://rb.gy/85e1h
 * Date: 2023/9/2
 * Skill: If you can use unordered_set, don't use set!
 * Runtime: 197 ms, faster than 49.28% of C++ online submissions
 * Memory Usage: 80.8 MB, less than 57.50% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= s.length <= 50
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> string_set;
        for (auto i: dictionary)
            string_set.insert(i);
        int sz = s.size();
        vector<int> dp(sz + 1, 0);
        for (int i = 0; i <= sz; i++)
            dp[i] = i;
        for (int i = 0; i < sz; i++) {
            string ss;
            for (int j = i; j >= 0; j--) {
                ss = s[j] + ss;
                if (string_set.find(ss) != string_set.end())
                    dp[i + 1] = min(dp[i + 1], dp[j]);
                else
                    dp[i + 1] = min(dp[i + 1], dp[j] + (i - j + 1));
            }
        }
        return dp[sz];
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
    vector<int> nums{1,3,2};
}