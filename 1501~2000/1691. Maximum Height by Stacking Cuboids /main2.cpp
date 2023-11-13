/**
 * Source: t.ly/h46vF
 * Date: 2023/11/13
 * Skill:
 * Runtime: 10 ms, faster than 81.90% of C++ online submissions
 * Memory Usage: 9.48 MB, less than 86.37% of C++ online submissions
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
        for (auto &i: cuboids) {
            sort(begin(i), end(i));
        }
        sort(begin(cuboids), end(cuboids));
        vector<int> dp;
        for (int i = 0; i < n; ++i) {
            dp.push_back(cuboids[i][2]);
            for (int j = i - 1; j >= 0; j--) {
                if (cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] &&
                        cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
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