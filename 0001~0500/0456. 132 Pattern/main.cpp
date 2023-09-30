/**
 * Source: ibit.ly/qYods
 * Date: 2023/9/30
 * Skill:
 * Runtime: 184 ms, faster than 5.28% of C++ online submissions
 * Memory Usage: 67.62 MB, less than 5.02% of C++ online submissions
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
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int sz = nums.size(), min_before = INT32_MAX;
        vector<int> smaller_before(sz, INT32_MAX), smaller_after(sz, INT32_MAX);
        set<int> after;
        for (int i = 0; i < sz; ++i) {
            smaller_before[i] = min_before;
            min_before = min(min_before, nums[i]);
            int j = sz - 1 - i;
            if (after.lower_bound(nums[j]) != begin(after))
                smaller_after[j] = *prev(after.lower_bound(nums[j]));
            after.insert(nums[j]);
        }
        for (int i = 0; i < nums.size(); i++)
            if (smaller_before[i] < smaller_after[i] && smaller_after[i] < nums[i])
                return true;
        return false;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
    ll a = 5e9;
    cout << 1e9 << endl;
    cout << a << endl;
}