/**
 * Source: t.ly/h46vF
 * Date: 2023/11/13
 * Skill:
 * Runtime: 101 ms, faster than 7.93% of C++ online submissions
 * Memory Usage: 11.54 MB, less than 33.85% of C++ online submissions
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


class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size(), res = 0;
        vector<array<int, 4>> shapes;
        for (int i = 0; i < n; i++) {
            shapes.push_back({cuboids[i][0], cuboids[i][1], cuboids[i][2], i});
            shapes.push_back({cuboids[i][0], cuboids[i][2], cuboids[i][1], i});
            shapes.push_back({cuboids[i][1], cuboids[i][0], cuboids[i][2], i});
            shapes.push_back({cuboids[i][1], cuboids[i][2], cuboids[i][0], i});
            shapes.push_back({cuboids[i][2], cuboids[i][0], cuboids[i][1], i});
            shapes.push_back({cuboids[i][2], cuboids[i][1], cuboids[i][0], i});
        }
        sort(begin(shapes), end(shapes));
        vector<int> dp;
        for (int i = 0; i < 6 * n; ++i) {
            dp.push_back(shapes[i][2]);
            for (int j = i - 1; j >= 0; j--) {
                if (shapes[i][0] >= shapes[j][0] && shapes[i][1] >= shapes[j][1] &&
                    shapes[i][2] >= shapes[j][2] && shapes[i][3] != shapes[j][3]) {
                    dp[i] = max(dp[i], dp[j] + shapes[i][2]);
                }
            }
            res = max(res, dp.back());
        }
        return res;
    }
};


int main() {
    Solution s;
}