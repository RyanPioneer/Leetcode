/**
 * Source: ibit.ly/EAoVn
 * Date: 2025/1/14
 * Skill:
 * Ref:
 * Runtime: 139 ms, faster than 52.02% of C++ online submissions
 * Memory Usage: 29.01 MB, less than 49.33% of C++ online submissions
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
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll lo = 1, hi = LLONG_MAX / 4;
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            ll sum = 0;
            for (int i = 0; i < workerTimes.size(); ++i) {
                sum += findMax(mid / workerTimes[i]);
            }
            if (sum < mountainHeight) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    ll findMax(ll target) {
        ll lo = 0, hi = min(100000LL, target);
        while (lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if (mid * (mid + 1) / 2 <= target) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
