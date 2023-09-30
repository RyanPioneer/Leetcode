/**
 * Source: ibit.ly/qYods
 * Date: 2023/9/30
 * Skill:
 * Runtime: 67 ms, faster than 63.56% of C++ online submissions
 * Memory Usage: 50.51 MB, less than 12.01% of C++ online submissions
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
        int sz = nums.size();
        vector<int> smaller_before(sz, INT32_MAX);
        for (int i = 1; i < sz; i++)
            smaller_before[i] = min(smaller_before[i - 1], nums[i - 1]);
        stack<int> s;
        s.push(nums[sz - 1]);
        for (int i = sz - 2; i >= 0; i--) {
            int next_min = INT32_MIN;
            while (!s.empty() && nums[i] > s.top()) {
                next_min = s.top(); s.pop();
            }
            if (next_min > smaller_before[i])
                return true;
            s.push(nums[i]);
        }
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