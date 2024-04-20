/**
 * Source: is.gd/8FtsiM
 * Date: 2024/4/20
 * Skill:
 * Ref:
 * Runtime: 150 ms, faster than 70.18% of C++ online submissions
 * Memory Usage: 114.50 MB, less than 84.21% of C++ online submissions
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
const int MX = 1e5+5;


class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size(), dp[MX];
        deque<int> q;

        for (int i = n - 1; i >= 0; i--) {
            while (!q.empty() && i + i + 2 < q.front()) q.pop_front();
            dp[i] = prices[i];
            if (!q.empty() && i + i + 2 < n) dp[i] += dp[q.front()];
            while (!q.empty() && dp[i] < dp[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return dp[0];
    }
};