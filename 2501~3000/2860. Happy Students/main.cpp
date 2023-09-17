/**
 * Source: https://rb.gy/hzymt
 * Date: 2023/9/17
 * Skill:
 * Runtime: 90 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 72.08 MB, less than 20.00% of C++ online submissions
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
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size(), res = (nums[0] > 0 ? 1 : 0);
        int pos = 0, cnt = 1;
        while (pos < sz ) {
            while (pos < sz && (nums[pos] >= cnt || (pos + 1 < sz && nums[pos + 1] <= cnt))) {
                pos++; cnt++;
            }
            if (pos < sz) {
                res++; pos++; cnt++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}