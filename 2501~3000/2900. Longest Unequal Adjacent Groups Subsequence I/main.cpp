/**
 * Source: ibit.ly/qXHK3
 * Date: 2023/10/15
 * Skill:
 * Runtime: 4 ms, faster than 93.75% of C++ online submissions
 * Memory Usage: 25.02 MB, less than 87.50% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        int prev_zero = -1, prev_one = -1, max_len = 0, max_tail = -1, sz = groups.size();
        int prev_pos[sz], sub_len[sz];
        for (int i = 0; i < sz; i++) {
            if (groups[i] == 0) {
                if (prev_one == -1) {
                    prev_pos[i] = -1;
                    sub_len[i] = 1;
                } else {
                    prev_pos[i] = prev_one;
                    sub_len[i] = sub_len[prev_one] + 1;
                }
                prev_zero = i;
            } else {
                if (prev_zero == -1) {
                    prev_pos[i] = -1;
                    sub_len[i] = 1;
                } else {
                    prev_pos[i] = prev_zero;
                    sub_len[i] = sub_len[prev_zero] + 1;
                }
                prev_one = i;
            }
            if (sub_len[i] > max_len) {
                max_len = sub_len[i];
                max_tail = i;
            }
        }
        vector<string> res;
        while (max_tail != -1) {
            res.push_back(words[max_tail]);
            max_tail = prev_pos[max_tail];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
    int c = test(2, 2);
    cout << c << endl;
}