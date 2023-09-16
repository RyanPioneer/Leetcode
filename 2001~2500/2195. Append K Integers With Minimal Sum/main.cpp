/**
 * Source: https://rb.gy/ocx53
 * Date: 2023/9/16
 * Skill:
 * Runtime: 108 ms, faster than 93.18% of C++ online submissions
 * Memory Usage: 66.41 MB, less than 46.59% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums.length <= 10 ** 5
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        ll res = 0;
        int cur = 1;
        for (auto i: nums) {
            if (i == cur)
                cur++;
            else if (i > cur) {
                ll cnt = min(k, i - cur);
                res += (cur * 2 + cnt - 1) * cnt / 2;
                k -= cnt;
                cur = i + 1;
                if (k == 0)
                    return res;
            }
        }
        res += ((ll)cur * 2 + (ll)k - 1) * (ll)k / 2;
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}