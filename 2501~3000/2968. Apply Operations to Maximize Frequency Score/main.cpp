/**
 * Source: jpeg.ly/RdGml
 * Date: 2023/12/18
 * Skill:
 * Ref:
 * Runtime: 166 ms, faster than 88.89% of C++ online submissions
 * Memory Usage: 85.59 MB, less than 44.44% of C++ online submissions
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
        ll res = 1, right = 0, len = SZ(nums), left = 0;
        sort(begin(nums), end(nums));
        ll right_sum = 0;
        while (right < len) {
            if (nums[right] - nums[0] + right_sum <= k) {
                right_sum += nums[right] - nums[0];
                right++;
            } else {
                break;
            }
        }
        res = right;
        ll left_sum = 0;
        for (int i = 1; i < len; i++) {
            left_sum += (i - left) * (nums[i] - nums[i - 1]);
            right_sum -= (right - i) * (nums[i] - nums[i - 1]);

            while (right < len && left_sum + right_sum + nums[right] - nums[i] <= k) {
                right_sum += nums[right] - nums[i];
                right++;
            }
            while (right < len && nums[right] - nums[i] < nums[i] - nums[left]) {
                right_sum += nums[right++] - nums[i];
                left_sum -= nums[i] - nums[left++];
                while (right < len && left_sum + right_sum + nums[right] - nums[i] <= k) {
                    right_sum += nums[right++] - nums[i];
                }
            }
            while (left > 0 && left_sum + right_sum + nums[i] - nums[left - 1] <= k) {
                left_sum += nums[i] - nums[--left];
            }
            res = max(res, right - left);
        }
        return res;
    }
};