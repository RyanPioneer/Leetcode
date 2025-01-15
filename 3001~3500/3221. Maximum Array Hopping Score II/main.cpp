/**
 * Source: ibit.ly/6hvLW
 * Date: 2025/1/15
 * Skill:
 * Ref:
 * Runtime: 39 ms, faster than 12.50% of C++ online submissions
 * Memory Usage: 122.36 MB, less than 56.25% of C++ online submissions
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

#define ll long long


class Solution {
public:
    long long maxScore(vector<int>& nums) {
        ll res = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < nums.size(); i++) {
            while (st.top() != 0 && nums[st.top()] <= nums[i]) {
                ll prev = st.top();
                st.pop();
                res -= (ll)nums[prev] * (prev - st.top());
            }
            res += (ll)nums[i] * (i - st.top());
            st.push(i);
        }
        return res;
    }
};
