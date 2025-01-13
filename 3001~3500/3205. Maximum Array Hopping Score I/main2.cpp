/**
 * Source: ibit.ly/DyekC
 * Date: 2024/8/24
 * Skill:
 * Ref:
 * Runtime: 20 ms, faster than 81.75% of C++ online submissions
 * Memory Usage: 32.06 MB, less than 9.52% of C++ online submissions
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


class Solution {
public:
    int maxScore(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> dp(n, 0);
        stack<int> st;
        for (int i = 1; i < n; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) st.pop();
            if (st.empty()) dp[i] = nums[i] * i;
            else dp[i] = dp[st.top()] + nums[i] * (i - st.top());
            st.push(i);
        }
        return dp[n-1];
    }
};