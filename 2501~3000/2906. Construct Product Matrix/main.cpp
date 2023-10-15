/**
 * Source: twtr.to/F4efi
 * Date: 2023/10/15
 * Skill:
 * Runtime: 204 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 127.02 MB, less than 50.00% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), mod = 12345;
        vector<vector<int>> res(n, vector<int>(m));
        ll post_product = 1, pre_product = 1;
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--) {
                res[i][j] = post_product;
                post_product = post_product * grid[i][j] % mod;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                res[i][j] = res[i][j] * pre_product % mod;
                pre_product = pre_product * grid[i][j] % mod;
            }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}