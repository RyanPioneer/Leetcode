/**
 * Source: https://rb.gy/xc0lq
 * Date: 2023/9/17
 * Skill:
 * Runtime: 3 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 23.22 MB, less than 37.50% of C++ online submissions
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int res = -1, sz = nums.size();
        for (int i = 0; i < sz - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (res != -1)
                    return -1;
                else
                    res = sz - i - 1;
            }
        }
        if (res == -1)
            return 0;
        else
            return nums[0] >= nums[sz - 1] ? res : -1;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}