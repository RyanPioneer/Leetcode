/**
 * Source: is.gd/wpsG1b
 * Date: 2024/4/18
 * Skill: 中位數貪心
 * Ref:
 * Runtime: 42 ms, faster than 97.70% of C++ online submissions
 * Memory Usage: 85.28 MB, less than 75.88% of C++ online submissions
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
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int c = 0;
        vector<int> pos;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            pos.push_back(i);
            c = max(c, 1);
            if (i - 1 >= 0 && nums[i - 1] == 1) {
                c = max(c, 2);
                if (i - 2 >= 0 && nums[i - 2] == 1) {
                    c = 3;
                }
            }
        }

        c = min(c, k);
        if (c + maxChanges >= k) {
            return max(c - 1, 0) + (k - c) * 2;
        }

        int sz = pos.size();
        vector<ll> presum(sz + 1);
        for (int i = 0; i < sz; i++) {
            presum[i + 1] = presum[i] + pos[i];
        }

        int len = k - maxChanges;
        ll res = LLONG_MAX;

        for (int right = len; right <= sz; right++) {
            int left = right - len;
            int mid = left + len / 2;
            ll s1 = (ll)pos[mid] * (mid - left) - (presum[mid] - presum[left]);
            ll s2 = presum[right] - presum[mid] - (ll)pos[mid] * (right - mid);
            res = min(res, s1 + s2);
        }
        return res + maxChanges * 2;
    }
};