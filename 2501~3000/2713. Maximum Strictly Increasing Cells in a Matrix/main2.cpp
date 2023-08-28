/**
 * Source: https://rb.gy/vlzz8
 * Date: 2023/8/28
 * Skill:
 * Runtime: 1395 ms, faster than 33.82% of C++ online submissions
 * Memory Usage: 380.75 MB, less than 26.85% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int maxIncreasingCells(vector<vector<int> >& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;
        unordered_map<int, int> row_map, col_map;
        vector<vector<int> > nums;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<int> v{mat[i][j], i, j};
                nums.push_back(v);
            }
        }
        sort(nums.begin(), nums.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] > b[0];
        });
        queue<vector<int> > q;
        for (int i = 0; i < nums.size(); i++) {
            while (q.size() > 0) {
                vector<int> v = q.front();
                if (v[0] > nums[i][0]) {
                    if (row_map.find(v[1]) != row_map.end())
                        row_map[v[1]] = max(row_map[v[1]], v[3]);
                    else
                        row_map[v[1]] = v[3];
                    if (col_map.find(v[2]) != col_map.end())
                        col_map[v[2]] = max(col_map[v[2]], v[3]);
                    else
                        col_map[v[2]] = v[3];
                    q.pop();
                } else
                    break;
            }
            int num = 0;
            if (row_map.find(nums[i][1]) != row_map.end())
                num = row_map[nums[i][1]];
            if (col_map.find(nums[i][2]) != col_map.end())
                num = max(num, col_map[nums[i][2]]);
            res = max(res, num + 1);
            vector<int> n{nums[i][0], nums[i][1], nums[i][2], num + 1};
            q.push(n);
        }
        return res;
    }

};

int main() {
    Solution s;
    vector<int> v1, v2;
    v1.push_back(3);
    v1.push_back(1);
    v2.push_back(3);
    v2.push_back(4);
    vector<vector<int> > mat;
    mat.push_back(v1);
    mat.push_back(v2);
    int res = s.maxIncreasingCells(mat);
    cout << res;
}

//static const auto io_sync_off = []() {
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();