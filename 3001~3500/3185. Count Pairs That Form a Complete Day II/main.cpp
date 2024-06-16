/**
 * Source: ibit.ly/bZhrf
 * Date: 2024/6/16
 * Skill:
 * Ref:
 * Runtime: 161 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 140.32 MB, less than 50.00% of C++ online submissions
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
const int MX = 5e5+7;


class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, ll> mp;
        for (auto &i: hours) {
            mp[i % 24]++;
        }
        ll res = 0;
        for (int i = 1; i < 12; i++) {
            res += mp[i] * mp[24 - i];
        }
        res += mp[12] * (mp[12] - 1) / 2 + mp[0] * (mp[0] - 1) / 2;
        return res;
    }
};