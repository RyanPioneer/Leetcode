/**
 * Source: tinyurl.com/ytro43uc
 * Date: 2023/10/27
 * Skill:
 * Runtime: 80 ms, faster than 98.51% of C++ online submissions
 * Memory Usage: 97.42 MB, less than 94.03% of C++ online submissions
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

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define ll long long

const int MX = 1e5+1;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        ll mod = 1e9+7;
        ll dp[MX] = {0};
        for (int i = 0; i + 1 < nextVisit.size(); i++)
            dp[i + 1] = (dp[i] + 1 + (dp[i] - dp[nextVisit[i]]) + 1 + mod) % mod;
        return dp[nextVisit.size() - 1];
    }
};


int main() {
//    Solution s;
}