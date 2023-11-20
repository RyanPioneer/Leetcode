/**
 * Source: twtr.to/8TJuD
 * Date: 2023/11/20
 * Skill:
 * Runtime: 519 ms, faster than 35.29% of C++ online submissions
 * Memory Usage: 226.26 MB, less than 5.88% of C++ online submissions
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
#include <functional>
#include <list>


using namespace std;

typedef pair<int, int> PII;

const int MX = 5 * 1e4 + 2;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), next_bigger[MX];
        map<PII, int> dp;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            next_bigger[i] = n;
            while (!st.empty() && heights[i] > heights[st.top()]) {
                next_bigger[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        function<int(int idx, int target)> helper;

        helper = [&](int idx, int target) {
            if (dp.find({idx, target}) != end(dp)) return dp[{idx, target}];
            if (heights[idx] > target) dp[{idx, target}] = idx;
            else if (next_bigger[idx] == n) dp[{idx, target}] = -1;
            else dp[{idx, target}] = helper(next_bigger[idx], target);
            return dp[{idx, target}];
        };

        vector<int> res;
        for (auto &q: queries) {
            int left = min(q[0], q[1]), right = max(q[0], q[1]);
            if (left == right || heights[left] < heights[right]) {
                res.push_back(right);
                continue;
            }
            res.push_back(helper(right, heights[left]));
        }
        return res;
    }
};