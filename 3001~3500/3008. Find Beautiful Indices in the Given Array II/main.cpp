/**
 * Source: jpeg.ly/EJBNr
 * Date: 2024/1/20
 * Skill: KMP
 * Ref:
 * Runtime: 169 ms, faster than 95.81% of C++ online submissions
 * Memory Usage: 97.18 MB, less than 54.51% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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
#include <list>


using namespace std;
#define ll long long
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;


class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> pos_a = preprocess(s, a), pos_b = preprocess(s, b);
        vector<int> res;
        int idx_b = 0;
        for (auto &i: pos_a) {
            while (idx_b < SZ(pos_b) && i > pos_b[idx_b] + k) idx_b++;
            if (idx_b == SZ(pos_b)) break;
            if (abs(i - pos_b[idx_b]) <= k) res.push_back(i);
        }
        return res;
    }
    vector<int> preprocess(string s, string pattern) {
        vector<int> p(pattern.length(), 0);
        int cur_len = 0;
        for (int i = 1; i < pattern.length(); i++) {
            while (cur_len > 0 && pattern[cur_len] != pattern[i]) cur_len = p[cur_len - 1];
            if (pattern[i] == pattern[cur_len]) cur_len++;
            p[i] = cur_len;
        }
        cur_len = 0;
        vector<int> res;
        for (int i = 0; i < s.length(); i++) {
            while (cur_len > 0 && pattern[cur_len] != s[i]) cur_len = p[cur_len - 1];
            if (s[i] == pattern[cur_len]) cur_len++;
            if (cur_len == pattern.length()) {
                res.push_back(i - pattern.length() + 1);
                cur_len = p[cur_len - 1];
            }
        }
        return res;
    }
};