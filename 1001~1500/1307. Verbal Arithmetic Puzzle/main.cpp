/**
 * Source: t.ly/5Y_lm
 * Date: 2023/9/22
 * Skill:
 * Runtime: TLE
 * Memory Usage:
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
    int nums[10];
    int map[27];
public:
    bool isSolvable(vector<string>& words, string result) {
        unordered_set<char> char_set;
        int len1 = 0, len2 = result.length();
        for (auto s: words) {
            if (s.length() > result.length())
                return false;
            for (int i = 0; i < s.size(); i++)
                char_set.insert(s[i]);
            len1 = max(len1, (int)s.length());
        }
        if (len2 - len1 >= 2)
            return false;
        for (auto c: result)
            char_set.insert(c);
        if (char_set.size() > 10)
            return false;
        for (int i = 0; i < 10; i++)
            nums[i] = 9-i;
        int idx = 0;
        for (auto c: char_set)
            map[c - 'A'] = idx++;
        return dfs(0, idx, words, result);
    }
    bool dfs(int idx, int sz, vector<string>& words, string result) {
        if (idx == sz) {
            if (nums[map[result[0] - 'A']] == 0)
                return false;
            int num1 = 0, num = 0;
            for (auto i: words) {
                if (nums[map[i[0] - 'A']] == 0)
                    return false;
                num = 0;
                for (auto j: i) {
                    num *= 10;
                    num += nums[map[j - 'A']];
                }
                num1 += num;
            }
            num = 0;
            for (auto i: result) {
                num *= 10;
                num += nums[map[i - 'A']];
            }
            return num1 == num;
        }
        for (int i = idx; i < 10; i++) {
            swap(nums[idx], nums[i]);
            if (dfs(idx + 1, sz, words, result))
                return true;
            swap(nums[idx], nums[i]);
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<string> nums2{"SEND","MORE"};
    string result = "MONEY";
    bool res = s.isSolvable(nums2, result);
    cout << res << endl;
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}