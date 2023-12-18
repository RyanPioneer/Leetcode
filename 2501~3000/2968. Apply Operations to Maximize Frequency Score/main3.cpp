/**
 * Source: jpeg.ly/RdGml
 * Date: 2023/12/18
 * Skill:
 * Ref:
 * Runtime: 184 ms, faster than 55.56% of C++ online submissions
 * Memory Usage: 86.35 MB, less than 44.44% of C++ online submissions
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
const int MX = 1e5+1;


class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(begin(nums), end(nums));
        int sz = SZ(nums), res = 1, right = 0;
        ll presum[MX] = {0};
        for (int i = 0; i < nums.size(); i++) presum[i + 1] = presum[i] + nums[i];
        auto check = [&](int left, int right) {
            int mid = (left + right) / 2;
            ll diff = (ll)nums[mid] * (mid - left) - (presum[mid] - presum[left]) +
                      (presum[right + 1] - presum[mid + 1]) - (ll)nums[mid] * (right - mid);
            return diff <= k;
        };
        for (int left = 0; left < sz; left++) {
            while (right < sz && check(left, right)) right++;
            res = max(res, right - left);
        }
        return res;
    }
};