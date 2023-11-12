/**
 * Source: https://rb.gy/itzx6
 * Date: 2023/11/12
 * Skill:
 * Runtime: 151 ms, faster than 99.88% of C++ online submissions
 * Memory Usage: 73.60 MB, less than 99.21% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx = *max_element(begin(nums), end(nums)), res = 0, mask = 0;
        int high_bit = mx ? 31 - __builtin_clz(mx) : -1;
        unordered_set<int> seen;
        for (int i = high_bit; i >= 0; i--) {
            mask |= 1 << i;
            seen.clear();
            int new_res = res | (1 << i);
            for (auto &i: nums) {
                if (seen.contains(new_res ^ (i & mask))) {
                    res = new_res;
                    break;
                }
                seen.insert(i & mask);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}