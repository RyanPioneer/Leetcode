/**
 * Source: https://rb.gy/4s3b8
 * Date: 2023/9/12
 * Skill:
 * Runtime: 77 ms, faster than 38.89% of C++ online submissions
 * Memory Usage: 17.42 MB, less than 37.86% of C++ online submissions
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
        int res = 0;
        vector<int> freq;
        unordered_map<char, int> char2freq;
        for (auto c: s)
            char2freq[c]++;
        for (auto c: char2freq)
            freq.push_back(c.second);
        sort(begin(freq), end(freq), [](const int a, const int b) {
            return a > b;
        });
        int cur_freq = INT32_MAX, cur_cnt = 0, sz = freq.size();
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != cur_freq) {
                while (cur_freq > freq[i] && cur_cnt >= 1) {
                    cur_freq--;
                    cur_cnt--;
                    res += cur_cnt;
                }
                cur_freq = freq[i];
                cur_cnt += 1;
            } else {
                while (i < sz && freq[i] == cur_freq) {
                    cur_cnt++;
                    i++;
                }
                cur_freq--;
                cur_cnt--;
                res += cur_cnt;
                i--;
            }
        }
        while (cur_cnt > 1 && cur_freq > 0) {
            cur_cnt--;
            cur_freq--;
            res += cur_cnt;
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
    string ss = "jbddhjemmnhaflahionjoddojoliimdcailihfdleahgbafnknblkheeicoonffenhhmgfhgmnjk";
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    int res = s.minDeletions(ss);
    cout << res << endl;
}