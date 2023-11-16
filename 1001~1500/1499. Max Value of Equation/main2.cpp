/**
 * Source: ibit.ly/hx5WV
 * Date: 2023/11/16
 * Skill:
 * Runtime: 230 ms, faster than 52.44% of C++ online submissions
 * Memory Usage: 89.15 MB, less than 94.14% of C++ online submissions
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

const int MX = 1e5+1;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<PII> q;
        int pos = 0, res = INT32_MIN, n = points.size();
        for (int i = 0; i < points.size(); i++) {
            if (!q.empty() && i == q.front().first) q.pop_front();
            if (pos == i) pos++;
            while (pos < n && points[pos][0] - points[i][0] <= k) {
                int num = points[pos][0] + points[pos][1];
                while (!q.empty() && num >= q.back().second) q.pop_back();
                q.push_back({pos, num});
                pos++;
            }
            if (!q.empty()) {
                res = max(res, q.front().second - points[i][0] + points[i][1]);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}