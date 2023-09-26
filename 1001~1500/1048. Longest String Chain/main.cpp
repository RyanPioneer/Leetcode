/**
 * Source: t.ly/CsJAv
 * Date: 2023/9/23
 * Skill:
 * Runtime: 2050 ms, faster than 5.03% of C++ online submissions
 * Memory Usage: 506.30 MB, less than 22.77% of C++ online submissions
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
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.length() < b.length();
        });
        int sz = words.size(), res = 0;
        vector<int> in_deg(sz, 0);
        vector<unordered_set<int>> adj_set(sz);
        for (int i = 0; i < sz - 1; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (words[j].length() > words[i].length() + 1)
                    break;
                if (words[j].length() == words[i].length() + 1 && check_subsequence(words[i], words[j])) {
                    in_deg[j]++;
                    adj_set[i].insert(j);
                }
            }
        }

        deque<int> q;
        for (int i = 0; i < sz; i++)
            if (in_deg[i] == 0)
                q.push_back(i);

        while (!q.empty()) {
            res++;
            int len = q.size();
            for (int j = 0; j < len; j++) {
                int cur = q.front(); q.pop_front();
                for (auto k: adj_set[cur])
                    q.pop_front(k);
            }
        }
        return res;

    }
    bool check_subsequence(string s, string l) {
        int pos = 0, sz = s.length(), time = 0;
        for (int i = 0; i < l.length() && pos < sz; i++) {
            if (l[i] == s[pos])
                pos++;
            else {
                if (time == 1)
                    return false;
                else
                    time++;
            }
        }
        return time <= 1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}