/**
 * Source: t.ly/Su_5A
 * Date: 2023/11/11
 * Skill:
 * Runtime: 364 ms, faster than 93.38% of C++ online submissions
 * Memory Usage: 159.50 MB, less than 95.36% of C++ online submissions
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

#define ll long long

typedef pair<int, int> pairs;

const int MX = 101;


class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), num;
        vector<vector<pairs>> col_st(n);
        vector<pairs> row_st;
        for (int i = m - 1; i >= 0; i--) {
            row_st.clear();
            for (int j = n - 1; j >= 0; j--) {
                auto &st = col_st[j];
                num = INT32_MAX;
                if (i == m - 1 && j == n - 1) {
                    num = 0;
                } else if (int g = grid[i][j]; g){
                    int right = j + g;
                    auto it = lower_bound(begin(row_st), end(row_st), right, [](const auto &a, const int b) {
                        return a.second > b;
                    });
                    if (it != end(row_st)) num = it->first;
                    int down = i + g;
                    it = lower_bound(begin(st), end(st), down, [](const auto &a, const int b) {
                        return a.second > b;
                    });
                    if (it != end(st)) num = min(num, it->first);
                }
                if (num == INT32_MAX) continue;
                num++;
                while (!st.empty() && num <= st.back().first) st.pop_back();
                st.emplace_back(num, i);
                while (!row_st.empty() && num <= row_st.back().first) row_st.pop_back();
                row_st.emplace_back(num, j);
            }
        }
        return num == INT32_MAX ? -1 : num;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{3,4,2,1}, {4,2,3,1},{2,1,0,0},{2,4,0,0}};
    vector<int> nums{2,3,5};
    int res = s.minimumVisitedCells(arr);
    cout << res;
}