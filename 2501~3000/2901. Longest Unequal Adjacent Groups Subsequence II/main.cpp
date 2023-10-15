/**
 * Source: ibit.ly/5orzu
 * Date: 2023/10/15
 * Skill:
 * Runtime: 72 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 28.38 MB, less than 100.00% of C++ online submissions
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
        int max_len = 0, max_tail = -1;
        int prev_pos[n], sub_len[n], word_len[n];
        for (int i = 0; i < n; i++)
            word_len[i] = words[i].length();
        for (int i = 0; i < n; i++) {
            sub_len[i] = 1;
            prev_pos[i] = -1;
            for (int j = i - 1; j >= 0; j--)
                if (word_len[i] == word_len[j] && groups[i] != groups[j]) {
                    int cnt = 0;
                    for (int k = 0; k < word_len[j]; k++)
                        if (words[i][k] != words[j][k]) {
                            cnt++;
                            if (cnt > 1)
                                break;
                        }
                    if (cnt == 1 && sub_len[i] < sub_len[j] + 1) {
                        sub_len[i] = sub_len[j] + 1;
                        prev_pos[i] = j;
                    }
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