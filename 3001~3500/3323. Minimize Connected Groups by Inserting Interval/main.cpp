/**
 * Source: ibit.ly/L7HEo
 * Date: 2025/4/1
 * Skill:
 * Ref:
 * Runtime: 167 ms, faster than 83.33% of C++ online submissions
 * Memory Usage: 196.07 MB, less than 75.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minConnectedGroups(vector<vector<int>>& intervals, int k)
    {
        int sz = intervals.size();
        sort(begin(intervals), end(intervals));

        vector<vector<int>> t;
        for (int i = 0; i < sz; i++) {
            int head = intervals[i][0], tail = intervals[i][1];
            while (i + 1 < sz && intervals[i + 1][0] <= tail) {
                tail = max(tail, intervals[i + 1][1]);
                i++;
            }
            t.push_back({ head, tail });
        }

        int res = t.size(), mx = 0, right = 0;
        for (int left = 0; left < t.size(); left++) {
            while (right < t.size() && t[right][0] <= t[left][1] + k) {
                right++;
            }
            mx = max(mx, right - left - 1);
        }
        return res - mx;
    }
};
