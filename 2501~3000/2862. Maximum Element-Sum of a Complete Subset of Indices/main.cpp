/**
 * Source: https://rb.gy/avfsk
 * Date: 2023/9/17
 * Skill:
 * Runtime: 34 ms, faster than 84.62% of C++ online submissions
 * Memory Usage: 40.41 MB, less than 69.23% of C++ online submissions
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
    long long maximumSum(vector<int>& nums) {
        ll res = 0;
        int sz = nums.size();
        for (int i = 1; i <= sz; ++i) {
            ll total = 0, j = 1;
            while (j * j * i <= sz) {
                total += nums[j * j * i - 1];
                j++;
            }
            res = max(res, total);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
    int res = s.maximumSum(nums);
    cout << res << endl;
}