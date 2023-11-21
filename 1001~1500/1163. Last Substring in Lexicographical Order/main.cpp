/**
 * Source: twtr.to/z8cnM
 * Date: 2023/11/21
 * Skill: Suffix array
 * Ref: twtr.to/Xhc6s
 * Runtime: TLE
 * Memory Usage:
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


#define SZ(X) ((int)(X).size())
#define ll long long
using namespace std;
const int MX = 40;
ll mod = 1e9+7;


class Solution {
public:
    string lastSubstring(string s) {
        s += '$';
        int n = SZ(s);
        vector<int> rank(n);
        vector<pair<char, int>> tmp(n);
        for (int i = 0; i < n; i++) tmp[i] = {s[i], i};
        sort(begin(tmp), end(tmp));
        rank[tmp[0].second] = 0;
        for (int i = 1; i < n; i++) {
            if (tmp[i].first == tmp[i - 1].first) {
                rank[tmp[i].second] = rank[tmp[i - 1].second];
            } else {
                rank[tmp[i].second] = rank[tmp[i - 1].second] + 1;
            }
        }

        vector<vector<int>> vec(n);
        for (int k = 0; (1 << k) < n; k++) {
            for (int i = 0; i < n; i++) vec[i] = {rank[i], rank[(i + (1 << k)) % n], i};
            sort(begin(vec), end(vec));
            rank[vec[0][2]] = 0;
            for (int i = 1; i < n; i++) {
                if (vec[i][0] == vec[i - 1][0] && vec[i][1] == vec[i - 1][1]) {
                    rank[vec[i][2]] = rank[vec[i - 1][2]];
                } else {
                    rank[vec[i][2]] = rank[vec[i - 1][2]] + 1;
                }
            }
        }
        s.pop_back();
        return s.substr(vec.back()[2]);
    }
};


int main() {
    Solution s;
    string res = s.lastSubstring("cacacb");
    vector<int> nums{-1,0,1,0,3,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
}