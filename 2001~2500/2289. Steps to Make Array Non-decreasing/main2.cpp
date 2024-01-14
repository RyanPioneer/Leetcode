/**
 * Source: jpeg.ly/dfWm1
 * Date: 2024/1/14
 * Skill:
 * Ref:
 * Runtime: 139 ms, faster than 77.00% of C++ online submissions
 * Memory Usage: 87.73 MB, less than 41.33% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;


class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int res = 0, n = SZ(nums);
        stack<int> st;
        vector<int> steps(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int step = 0;
            while (!st.empty() && nums[i] > nums[st.top()]) {
                step = max(step + 1, steps[st.top()]);
                st.pop();
            }
            res = max(res, steps[i] = step);
            st.push(i);
        }
        return res;
    }
};