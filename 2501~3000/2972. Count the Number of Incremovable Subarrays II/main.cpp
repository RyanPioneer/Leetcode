/**
 * Source: is.gd/bWyu9N
 * Date: 2023/12/24
 * Skill:
 * Ref:
 * Runtime: 333 ms, faster than 12.50% of C++ online submissions
 * Memory Usage: 128.82 MB, less than 12.50% of C++ online submissions
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
    long long incremovableSubarrayCount(vector<int>& nums) {
        ll res = 0;
        int len = SZ(nums), left = 2;
        for (int i = 1; i < len; i++) {
            if (nums[i] <= nums[i - 1]) break;
            left++;
        }
        map<int, int> mp;
        for (int i = 0; i < len; i++) {
            if (mp.empty() || nums[i] > mp.rbegin()->first) {
                mp[nums[i]] = i;
            }
        }
        int right_min = INT32_MAX;
        for (int i = len - 1; i >= 0; i--) {
            if (mp.find(nums[i]) != end(mp) && mp[nums[i]] == i) mp.erase(nums[i]);
            auto it = mp.lower_bound(right_min);
            if (it == end(mp)) {
                res += min(left, i + 1);
            } else {
                int pos = it->second;
                res += min(pos + 1, left);
            }
            if (nums[i] >= right_min) break;
            right_min = nums[i];
        }
        return res;
    }
};
