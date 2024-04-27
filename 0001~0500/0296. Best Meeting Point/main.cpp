/**
 * Source: t.ly/EG6-N
 * Date: 2024/4/25
 * Skill:
 * Ref: https://www.cnblogs.com/grandyang/p/5291058.html
 * Runtime: 10 ms, faster than 56.99% of C++ online submissions
 * Memory Usage: 14.92 MB, less than 20.97% of C++ online submissions
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
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<int> rows, cols;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    rows.push_back(j);
                    cols.push_back(i);
                }
            }
        }

        function<void(vector<int>&)> helper = [&](vector<int>& arr) {
            int start = 0, end = arr.size() - 1;

            sort(begin(arr), end(arr));
            while (start < end) {
                res += arr[end--] - arr[start++];
            }
        };

        helper(rows);
        helper(cols);
        return res;
    }
};