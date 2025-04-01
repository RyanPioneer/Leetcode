/**
 * Source: is.gd/g8xFTn
 * Date: 2025/1/22
 * Skill:
 * Ref:
 * Runtime: 461 ms, faster than 30.39% of C++ online submissions
 * Memory Usage: 142.88 MB, less than 81.62% of C++ online submissions
 * Time complexity:
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
    int minOperations(vector<int>& nums) {
        int res = 0;

        auto greatestDivisor = [](int n) {
            for (int i = 2; i <= sqrt(n); ++i) {
                if (n % i == 0) {
                    return n / i;
                }
            }
            return -1;
        };

        for (int i = nums.size() - 2; i >= 0; --i) {
            while (nums[i] > nums[i+1]) {
                res++;
                int div = greatestDivisor(nums[i]);
                if (div == -1) return -1;
                nums[i] /= div;
            }
        }
        return res;
    }
};
