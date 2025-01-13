/**
 * Source: ibit.ly/mCnt5
 * Date: 2025/1/5
 * Skill:
 * Ref:
 * Runtime: 126 ms, faster than 55.85% of C++ online submissions
 * Memory Usage: 97.55 MB, less than 82.83% of C++ online submissions
 * Time complexity: WA
 * Space complexity:
 * Constraints:
 *      1 <= nums.length <= 10 ** 5
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


class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int res = nums.size(), prev = nums[0] - k;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > prev) {
                int dis = nums[i] - prev;
                prev = dis > k ? nums[i] - k : prev + 1;
            } else {
                if (nums[i] + k <= prev) {
                    res--;
                } else {
                    prev++;
                }
            }
        }
        return res;
    }
};
