/**
 * Source: https://rb.gy/4s3b8
 * Date: 2023/9/12
 * Skill:
 * Runtime: 51 ms, faster than 74.86% of C++ online submissions
 * Memory Usage: 17.20 MB, less than 92.40% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (auto c: s)
            freq[c - 'a']++;
        sort(begin(freq), end(freq), greater<int>());
        int prev = INT32_MAX, keep = 0;
        for (auto i: freq) {
            if (!i || !prev)
                break;
            prev = min(prev - 1, i);
            keep += prev;
        }
        return s.length() - keep;
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
    string ss = "jbddhjemmnhaflahionjoddojoliimdcailihfdleahgbafnknblkheeicoonffenhhmgfhgmnjk";
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    int res = s.minDeletions(ss);
    cout << res << endl;
}