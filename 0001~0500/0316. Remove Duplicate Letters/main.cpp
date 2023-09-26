/**
 * Source: t.ly/AnRfu
 * Date: 2023/9/20
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.02 MB, less than 13.89% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        unordered_map<char, int> cnt;
        vector<bool> visited(26, false);
        for (auto c: s)
            cnt[c]++;
        for (auto c: s) {
            cnt[c]--;
            if (!visited[c - 'a']) {
                while (!res.empty() && c < res.back() && cnt[res.back()] > 0) {
                    visited[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                visited[c - 'a'] = true;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums2{8, 8, 9, 1, 6, 3, 0, 4, 1, 4, 1, 8, 0, 3, 1, 2, 7, 9, 3, 2, 5, 5, 2, 7, 9, 5, 2, 2};
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string ss = "bcabc";
    string res = s.removeDuplicateLetters(ss);
    cout << res << endl;
}