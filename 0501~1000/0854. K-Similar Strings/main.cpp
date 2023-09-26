/**
 * Source: t.ly/3O2ly
 * Date: 2023/9/26
 * Skill:
 * Runtime: 230 ms, faster than 41.14% of C++ online submissions
 * Memory Usage: 85.58 MB, less than 31.11% of C++ online submissions
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
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        deque<string> q;
        unordered_set<string> visited;
        visited.insert(s1);
        int step = 0, len = s1.length();
        q.push_back(s1);
        while (!q.empty()) {
            step++;
            int sz = q.size();
            while (sz--) {
                string ss = q.front(); q.pop_front();
                int i = 0, j = 0;
                for (i = 0; i < len; i++)
                    if (ss[i] != s2[i])
                        break;
                for (j = i + 1; j < len; j++)
                    if (ss[j] == s2[i]) {
                        string ss2 = ss;
                        swap(ss2[i], ss2[j]);
                        if (ss2 == s2)
                            return step;
                        if (visited.find(ss2) == visited.end()) {
                            visited.insert(ss2);
                            q.push_back(ss2);
                        }
                    }
            }
        }
        return -1;
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