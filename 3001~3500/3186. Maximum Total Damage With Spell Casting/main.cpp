/**
 * Source: ibit.ly/LRK-d
 * Date: 2024/6/16
 * Skill:
 * Ref:
 * Runtime: 575 ms, faster than 60.00% of C++ online submissions
 * Memory Usage: 222.56 MB, less than 60.00% of C++ online submissions
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
typedef pair<int, ll> PIL;
#define MK make_pair


class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, ll> mp;
        for (auto &i: power) mp[i] += i;
        ll res = 0;
        deque<PIL> q;
        for (auto &i: mp) {
            ll prev = 0, prevNum = -1;
            while (!q.empty() && q.front().first < i.first - 2) {
                prevNum = q.front().first;
                prev = q.front().second;
                q.pop_front();
            }
            ll cur = prev + i.second;
            res = max(res, cur);
            if (prevNum != -1) {
                q.push_front(MK(prevNum, prev));
            }
            if (q.empty() || cur > q.back().second) {
                q.push_back(MK(i.first, cur));
            }
        }
        return res;
    }
};