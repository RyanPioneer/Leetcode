/**
 * Source: bit.ly/3UDmYzE
 * Date: 2024/5/1
 * Skill:
 * Ref:
 * Runtime: 76 ms, faster than 43.82% of C++ online submissions
 * Memory Usage: 42.43 MB, less than 79.78% of C++ online submissions
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

const int MX = 1e4+10;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double preSum[MX] = {0};

        function<bool(double)> check = [&](double num) {
            double preMin = 0;

            for (int i = 0; i < k - 1; i++) {
                preSum[i + 1] = preSum[i] + nums[i] - num;
            }
            for (int i = k - 1; i < n; i++) {
                preSum[i + 1] = preSum[i] + nums[i] - num;
                preMin = min(preMin, preSum[i - k + 1]);
                if (preSum[i + 1] >= preMin) return true;
            }
            return false;
        };

        double lo = *min_element(begin(nums), end(nums));
        double hi = *max_element(begin(nums), end(nums));

        while (hi - lo >= 1e-5) {
            double mid = lo + (hi - lo) / 2;
            if (check(mid)) lo = mid;
            else hi = mid;
        }
        return lo;
    }
};