/**
 * Source: t.ly/fTO1h
 * Date: 2023/11/14
 * Skill:
 * Runtime: 13 ms, faster than 50.57% of C++ online submissions
 * Memory Usage: 10.71 MB, less than 29.30% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 1000
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


const int MX = 1001;


class Solution {
    int dp[MX][MX] = {0}, res[MX] = {0}, n;
public:
    int minSteps(int n) {
        this->n = n;
        for (int i = 2; i <= n; i++) res[i] = i;
        dfs(1, 1, 1);
        return res[n];
    }
    void dfs(int cur_sum, int copy_num, int time) {
        if (cur_sum > n || copy_num > n) return;
        if (dp[cur_sum][copy_num] != 0) return;
        dp[cur_sum][copy_num] = 1;
        res[cur_sum] = min(res[cur_sum], time);
        dfs(cur_sum, cur_sum, time + 1);
        dfs(cur_sum + copy_num, copy_num, time + 1);
    }
};


int main() {
    Solution s;
}