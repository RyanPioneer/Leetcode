/**
 * Source: ibit.ly/N3AvW
 * Date: 2024/6/17
 * Skill:
 * Ref:
 * Runtime: 97 ms, faster than 72.95% of C++ online submissions
 * Memory Usage: 75.30 MB, less than 74.16% of C++ online submissions
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
    int maxSubarrayLength(vector<int>& nums) {
        stack<int> st;
        int n = nums.size(), res = 0;
        for (int right = n - 1; right > 0 && !res; right--) {
            if (nums[right] < nums[0]) {
                res = right + 1;
            } else if (st.empty() || nums[right] < nums[st.top()]){
                st.push(right);
            }
        }
        for (int i = 1; i < n - 1 && !st.empty(); i++) {
            if (!st.empty() && st.top() == i) {
                st.pop();
            }
            while (!st.empty() && nums[i] > nums[st.top()]) {
                res = max(res, st.top() - i + 1);
                st.pop();
            }
        }
        return res;
    }
};