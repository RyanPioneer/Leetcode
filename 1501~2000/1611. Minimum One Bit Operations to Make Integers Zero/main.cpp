/**
 * Source: t.ly/jxeuh
 * Date: 2023/9/20
 * Skill:
 * Runtime: 23 ms, faster than 7.02% of C++ online submissions
 * Memory Usage: 25.07 MB, less than 5.57% of C++ online submissions
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
    unordered_map<string, int> map1, map2;
public:
    int minimumOneBitOperations(int n) {
        string s = bitset<32>(n).to_string();
        return dfs(s);
    }
    int dfs(string s) {
        if (s == "0")
            return 0;
        if (s == "1")
            return 1;
        if (map1.find(s) != map1.end())
            return map1[s];
        if (s[0] == '0')
            map1[s] = dfs(s.substr(1));
        else {
            string t = s.substr(1);
            string t2 = t;
            t2[0] = '1';
            for (int i = 1; i < t2.length(); i++)
                t2[i] = '0';
            map1[s] = dfs2(t) + 1 + dfs(t2);
        }
        return map1[s];
    }
    int dfs2(string s) {
        if (s == "1")
            return 0;
        if (s == "0")
            return 1;
        if (map2.find(s) != map2.end())
            return map2[s];
        if (s[0] == '1')
            map2[s] = dfs(s.substr(1));
        else {
            string t = s.substr(1);
            string t2 = t;
            t2[0] = '1';
            for (int i = 1; i < t2.length(); i++)
                t2[i] = '0';
            map2[s] = dfs2(t) + 1 + dfs(t2);
        }
        return map2[s];
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
}