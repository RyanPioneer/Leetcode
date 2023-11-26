/**
 * Source: is.gd/wy2cUw
 * Date: 2023/11/26
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 20.24 MB, less than 50.00% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e4 + 2;


class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int dp[MX] = {0}, sz = SZ(prices);
        deque<int> q;
        for (int i = sz; i >= 1; i--) {
            while (!q.empty() && q.front() > i + i + 1) q.pop_front();
            dp[i] = prices[i - 1] + (i + i >= sz ? 0 : dp[q.front()]);
            while (!q.empty() && dp[q.back()] >= dp[i]) q.pop_back();
            q.push_back(i);
        }
        return dp[1];
    }
};