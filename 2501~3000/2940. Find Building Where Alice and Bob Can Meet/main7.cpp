/**
 * Source: twtr.to/8TJuD
 * Date: 2023/11/20
 * Skill: Binary Lifting
 * Runtime: 439 ms, faster than 41.18% of C++ online submissions
 * Memory Usage: 178.74 MB, less than 23.53% of C++ online submissions
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

const int MX = 5 * 1e4 + 2;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        heights.push_back(INT32_MAX);
        int n = heights.size(), father[MX][16] = {0};
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] > heights[st.top()]) {
                father[st.top() + 1][0] = i + 1;
                st.pop();
            }
            st.push(i);
        }
        for (int i = 1; i < 16; i++) {
            for (int j = 1; j <= n; j++) {
                father[j][i] = father[father[j][i - 1]][i - 1];
            }
        }

        vector<int> res;
        for (auto &q: queries) {
            int left = min(q[0], q[1]) + 1, right = max(q[0], q[1]) + 1;
            if (left == right || heights[left - 1] < heights[right - 1]) {
                res.push_back(right - 1);
                continue;
            }
            for (int i = 15; i >= 0; i--) {
                if (father[right][i] != 0 && heights[father[right][i] - 1] <= heights[left - 1]) {
                    right = father[right][i];
                }
            }
            right = father[right][0];
            if (right == n) res.push_back(-1);
            else res.push_back(right - 1);
        }
        return res;
    }
};