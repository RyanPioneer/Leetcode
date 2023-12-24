/**
 * Source: is.gd/cFterc
 * Date: 2023/12/24
 * Skill:
 * Ref:
 * Runtime: 143 ms, faster than 66.67% of C++ online submissions
 * Memory Usage: 79.09 MB, less than 66.67% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        ll total = accumulate(begin(nums), end(nums), 0ll);
        for (int i = SZ(nums) - 1; i > 1; i--) {
            if (total - nums[i] > nums[i]) {
                return total;
            }
            total -= nums[i];
        }
        return -1;
    }
};