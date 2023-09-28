/**
 * Source: ibit.ly/Nez5i
 * Date: 2023/9/27
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.46 MB, less than 7.16% of C++ online submissions
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
    string decodeAtIndex(string s, int k) {
        ll cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                cnt++;
                if (cnt == k) {
                    string res;
                    res.push_back(s[i]);
                    return res;
                }
            } else {
                ll num = s[i] - '0';
                if (cnt * num < k)
                    cnt *= num;
                else if (k % cnt == 0)
                    return decodeAtIndex(s.substr(0, i), cnt);
                else
                    return decodeAtIndex(s.substr(0, i), k % cnt);
            }
        }
        return "";
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