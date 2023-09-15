/**
 * Source: https://rb.gy/nd50a
 * Date: 2023/9/15
 * Skill:
 * Runtime: 159 ms, faster than 98.64% of C++ online submissions
 * Memory Usage: 94.72 MB, less than 67.42% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int sz = floor.length();
        vector<int> dp(sz, 0);
        dp[0] = (floor[0] == '1');
        for (int i = 1; i < sz; i++)
            dp[i] = dp[i - 1] + (floor[i] == '1');
        for (int i = 1; i <= numCarpets; i++) {
            vector<int> dp2 = dp;
            for (int j = 0; j < sz; j++) {
                if (j < carpetLen)
                    dp[j] = 0;
                else
                    dp[j] = min(dp[j - 1] + (floor[j] == '1'), dp2[j - carpetLen]);
            }
        }
        return dp[sz - 1];
    }
};


int main() {
//    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
}