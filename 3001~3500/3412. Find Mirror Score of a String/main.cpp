/**
 * Source: ibit.ly/tCGyP
 * Date: 2025/1/5
 * Skill:
 * Ref:
 * Runtime: 18 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 16.96 MB, less than 75.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= s.length <= 10 ** 5
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


class Solution {
public:
    long long calculateScore(string s) {
        ll res = 0;
        unordered_map<int, vector<int> > mp;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            int rev = 25 - idx;
            if (!mp[rev].empty()) {
                res += i - mp[rev].back();
                mp[rev].pop_back();
            } else {
                mp[idx].push_back(i);
            }
        }
        return res;
    }
};
