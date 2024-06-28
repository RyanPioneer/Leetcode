/**
 * Source: ibit.ly/tNMiD
 * Date: 2024/6/28
 * Skill:
 * Ref:
 * Runtime: 293 ms, faster than 60.89% of C++ online submissions
 * Memory Usage: 133.86 MB, less than 26.81% of C++ online submissions
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
const int MX = 32;
#define ll long long


class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int sz = queries.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < sz; i++) {
            mp[queries[i][0] ^ queries[i][1]].push_back(i);
        }
        vector<vector<int>> res;
        for (int i = 0; i < sz; i++) {
            res.push_back({-1, -1});
        }

        for (int len = 1; len < MX; len++) {
            ll total = 0;
            for (int i = 0; i < s.length(); i++) {
                total = total * 2 + (s[i] - '0');
                if (i >= len) {
                    total -= (s[i-len] - '0') * (1ll << len);
                }
                if (mp.find(total) != end(mp)) {
                    for (auto &j: mp[total]) {
                        res[j] = {i - len + 1, i};
                    }
                    mp.erase(total);
                }
            }
        }
        return res;
    }
};