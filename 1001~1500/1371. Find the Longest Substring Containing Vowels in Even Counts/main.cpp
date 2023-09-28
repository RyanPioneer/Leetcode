/**
 * Source: ibit.ly/HkchO
 * Date: 2023/9/27
 * Skill:
 * Runtime: 92 ms, faster than 44.42% of C++ online submissions
 * Memory Usage: 16.5 MB, less than 18.60% of C++ online submissions
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
    int findTheLongestSubstring(string s) {
        unordered_map<int, int>cnt2pos;
        unordered_map<char, int> char2num {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        int cur_num = 0, res = 0;
        cnt2pos[cur_num] = -1;
        for (int i = 0; i < s.length(); i++) {
            if (char2num.find(s[i]) == char2num.end()) {
                if (cnt2pos.find(cur_num) != cnt2pos.end())
                    res = max(res, i - cnt2pos[cur_num]);
            } else {
                int num = (1 << char2num[s[i]]);
                cur_num ^= num;
                if (cnt2pos.find(cur_num) != cnt2pos.end())
                    res = max(res, i - cnt2pos[cur_num]);
                else
                    cnt2pos[cur_num] = i;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {2, 10},
                             {1, 10},
                             {2, 3},
                             {6,10},
                             {4,3},
                             {8,6},
                             {5,8},
                             {7,6}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}