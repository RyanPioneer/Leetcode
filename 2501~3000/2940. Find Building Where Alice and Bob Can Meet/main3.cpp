/**
 * Source: twtr.to/8TJuD
 * Date: 2023/11/19
 * Skill:
 * Runtime: 376 ms, faster than 47.06% of C++ online submissions
 * Memory Usage: 190.77 MB, less than 23.53% of C++ online submissions
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

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> res(queries.size(), -1);
        vector<vector<PII>> nums(heights.size());
        for (int i = 0; i < queries.size(); i++) {
            int left = min(queries[i][0], queries[i][1]), right = max(queries[i][0], queries[i][1]);
            if (left == right || heights[right] > heights[left]) {
                res[i] = right;
            } else {
                nums[right].emplace_back(heights[left], i);
            }
        }
        priority_queue<PII, vector<PII>, greater<>> pq;
        for (int i = 0; i < heights.size(); i++) {
            while (!pq.empty() && heights[i] > pq.top().first) {
                res[pq.top().second] = i;
                pq.pop();
            }
            for (auto &p: nums[i]) {
                pq.emplace(p);
            }
        }
        return res;
    }
};