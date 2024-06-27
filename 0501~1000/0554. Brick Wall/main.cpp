/**
 * Source: ibit.ly/A3KxA
 * Date: 2024/6/26
 * Skill:
 * Ref:
 * Runtime: 32 ms, faster than 63.41% of C++ online submissions
 * Memory Usage: 26.80 MB, less than 21.10% of C++ online submissions
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


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<ll, int> mp;
        ll cur;
        for (auto &i: wall) {
            cur = 0;
            for (auto &j: i) {
                cur += j;
                mp[cur]++;
                mp[cur+1]--;
            }
        }

        int res = wall.size(), cnt = 0, n = wall.size();
        for (auto &i: mp) {
            if (i.first == cur) break;
            cnt += i.second;
            res = min(res, n - cnt);
        }
        return res;
    }
};