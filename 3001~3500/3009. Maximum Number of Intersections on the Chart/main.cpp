/**
 * Source: t.ly/yRVqu
 * Date: 2024/4/25
 * Skill:
 * Ref:
 * Runtime: 345 ms, faster than 65.33% of C++ online submissions
 * Memory Usage: 108.87 MB, less than 70.67% of C++ online submissions
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

#define ll long long
using namespace std;


class Solution {
public:
    int maxIntersectionCount(vector<int>& y) {
        int n = y.size(), curNum = 0, res = 1;
        int dir = y[1] - y[0];
        map<float, int> mp;

        mp[min(y[0], y[1])]++;
        mp[max(y[0], y[1]) + 0.1]--;

        for (int i = 2; i < n; i++) {
            int d = y[i] - y[i - 1];

            if ((ll)d * dir > 0) {
                if (d > 0) {
                    mp[y[i - 1] + 0.1]++;
                    mp[y[i] + 0.1]--;
                } else {
                    mp[y[i - 1]]--;
                    mp[y[i]]++;
                }
            } else {
                if (d > 0) {
                    mp[y[i - 1] + 0.1]++;
                    mp[y[i] + 0.1]--;
                } else {
                    mp[y[i - 1]]--;
                    mp[y[i]]++;
                }
            }
            dir = d;
        }

        for (auto &i: mp) {
            curNum += i.second;
            res = max(res, curNum);
        }
        return res;
    }
};