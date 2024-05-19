/**
 * Source: ibit.ly/BKKPD
 * Date: 2024/5/16
 * Skill:
 * Ref:
 * Runtime: 341 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 277.72 MB, less than 100.00% of C++ online submissions
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
    vector<int> maxUpgrades(vector<int>& count, vector<int>& upgrade, vector<int>& sell, vector<int>& money) {
        vector<int> res;
        for (int i = 0; i < count.size(); i++) {
            int left = 0, right = count[i];
            while (left < right) {
                ll mid = (left + right + 1) / 2;
                ll num = count[i] - mid;
                ll m = money[i] + num * sell[i];
                if (m >= mid * upgrade[i]) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            res.push_back(left);
        }
        return res;
    }
};