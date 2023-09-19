/**
 * Source: https://rb.gy/umtx6
 * Date: 2023/9/19
 * Skill:
 * Runtime: TLE
 * Memory Usage:
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
    int dp[10002][102] = {0};
public:
    int superEggDrop(int k, int n) {
        if (n == 0)
            return 0;
        if (k == 1 || n == 1)
            return n;
        if (dp[n][k] != 0)
            return dp[n][k];
        int num = INT32_MAX;
        for (int i = 1; i <= n; i++) {
            int step1 = superEggDrop(k - 1, i - 1);
            int step2 = superEggDrop(k, n - i);
            num = min(num, max(step1, step2));
        }
        dp[n][k] = num + 1;
        return dp[n][k];
    }
};

int main() {
    Solution s;
    vector<int> nums2{8, 8, 9, 1, 6, 3, 0, 4, 1, 4, 1, 8, 0, 3, 1, 2, 7, 9, 3, 2, 5, 5, 2, 7, 9, 5, 2, 2};
    vector<vector<int>> arr1{{0, 0},
                             {1, 1},
                             {2, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    int res = s.superEggDrop(2, 4);
    cout << res << endl;
}