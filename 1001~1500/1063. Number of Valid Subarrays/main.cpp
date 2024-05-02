/**
 * Source: t.ly/L8_5_
 * Date: 2024/5/2
 * Skill:
 * Ref:
 * Runtime: 45 ms, faster than 83.77% of C++ online submissions
 * Memory Usage: 47.11 MB, less than 27.27% of C++ online submissions
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
    int validSubarrays(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> rightSmaller(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) rightSmaller[i] = st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            res += rightSmaller[i] - i;
        }
        return res;
    }
};