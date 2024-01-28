/**
 * Source: jpeg.ly/rnGu5
 * Date: 2024/1/28
 * Skill:
 * Ref:
 * Runtime: TLE
 * Memory Usage:
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


class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = SZ(nums), prev_min = nums[0];
        ll res = nums[0] + nums[1], back_min = 0;
        multiset<int> Set;
        for (int i = 2; i - 1 <= dist && i < n; i++) Set.insert(nums[i]);
        int time = 0;
        for (auto iter = Set.begin(); iter != Set.end(); iter++) {
            back_min += *iter;
            time++;
            if (time == k - 2) break;
        }
        res += back_min;
        // cout << res << endl;
        for (int i = 2; n - i - 1 >= k - 2 ; i++) {
            Set.erase(Set.lower_bound(nums[i]));
            auto iter = begin(Set);
            std::advance(iter, k - 3);
            int num = (Set.size() < k - 2) ? nums[i + dist] : *iter;
            if (num >= nums[i] || Set.size() < k - 2) back_min += num - nums[i];
            if (i + dist < n) {
                Set.insert(nums[i + dist]);
                if (nums[i + dist] < num) back_min += nums[i + dist] - num;
            }
            res = min(res, prev_min + nums[i] + back_min);
            // cout << res << endl;
        }
        return res;
    }
};