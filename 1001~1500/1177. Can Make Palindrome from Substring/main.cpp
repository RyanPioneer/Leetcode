/**
 * Source: jpeg.ly/dLX3_
 * Date: 2024/1/14
 * Skill:
 * Ref:
 * Runtime: 370 ms, faster than 64.57% of C++ online submissions
 * Memory Usage: 151.10 MB, less than 46.29% of C++ online submissions
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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<vector<int>> presum;
        vector<int> cnt(26, 0);
        presum.push_back(cnt);
        for (auto c: s) {
            cnt[c - 'a']++;
            presum.push_back(cnt);
        }
        for (auto &q: queries) {
            int lo = q[0], hi = q[1], k = q[2], odd = 0;
            if ((hi - lo) % 2 == 0) odd--;
            for (int i = 0; i < 26; i++) {
                if ((presum[hi + 1][i] - presum[lo][i]) % 2 == 1) odd++;
            }
            res.push_back(k >= odd / 2);
        }
        return res;
    }
};