/**
 * Source: twtr.to/xoOQj
 * Date: 2023/11/22
 * Skill:
 * Ref:
 * Runtime: 38 ms, faster than 63.98% of C++ online submissions
 * Memory Usage: 29.92 MB, less than 37.14% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
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


#define SZ(X) ((int)(X).size())
#define ll long long
using namespace std;
typedef pair<int, int> PII;
const int MX = 1e4;
ll mod = 1e9+7;


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int res = 0, sz = SZ(nums);
        stack<int> st;
        for (int i = 0; i < sz; i++) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }
        for (int i = sz - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                res = max(res, i - st.top());
                st.pop();
            }
            if (st.empty()) break;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
}