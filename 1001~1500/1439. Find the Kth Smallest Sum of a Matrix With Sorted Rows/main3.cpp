/**
 * Source: t.ly/oHyt8
 * Date: 2023/11/10
 * Skill:
 * Runtime: 25 ms, faster than 83.00% of C++ online submissions
 * Memory Usage: 8.64 MB, less than 98.02% of C++ online submissions
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

const int MX = 1e5 + 1;

class Solution {
    int m, n, mi = 0;
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; ++i) mi += mat[i][0];
        int left = mi, right = INT32_MAX / 2;
        while (left < right) {
            int mid = (left + right) / 2;
            if (checkOk(mat, k, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    bool checkOk(vector<vector<int>>& mat, int k, int target) {
        int count = 1, cur_sum = mi;
        dfs(mat, 0, cur_sum, count, k, target);
        return count >= k;
    }
    void dfs(vector<vector<int>>& mat, int row, int &cur_sum, int &count, int &k, int &target) {
        if (count >= k || row == m) return;
        for (int i = 0; i < n; i++) {
            if (cur_sum + mat[row][i] - mat[row][0] <= target) {
                if (i > 0) count++;
                cur_sum += mat[row][i] - mat[row][0];
                dfs(mat, row + 1, cur_sum, count, k, target);
                cur_sum -= mat[row][i] - mat[row][0];
            } else {
                break;
            }
        }
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}