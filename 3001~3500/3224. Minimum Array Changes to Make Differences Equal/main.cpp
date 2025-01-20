/**
 * Source: jpeg.ly/pcdK_
 * Date: 2025/1/18
 * Skill:
 * Ref:
 * Runtime: 11 ms, faster than 83.89% of C++ online submissions
 * Memory Usage: 100.99 MB, less than 99.44% of C++ online submissions
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
const int MX = 1e5+10;


class Solution {
    int diff[MX] = {0};
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            int mi = min(nums[i], nums[n - i - 1]);
            int mx = max(nums[i], nums[n - i - 1]);
            int d1 = mi, d2 = k - mx;
            diff[k] += 2;
            diff[mx - mi + max(d1, d2)] -= 1;
            diff[mx - mi] -= 1;
            if (mx > mi) diff[mx - mi - 1] += 1;
        }
        
        int res = INT32_MAX, cnt = 0;
        for (int i = k; i >= 0; i--) {
            cnt += diff[i];
            res = min(res, cnt);
        }
        return res;
    }
};
