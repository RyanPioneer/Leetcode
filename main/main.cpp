/**
 * Source: is.gd/9jOKTp
 * Date: 2023/11/23
 * Skill:
 * Ref:
 * Runtime: 6 ms, faster than 52.63% of C++ online submissions
 * Memory Usage: 19.82 MB, less than 29.82% of C++ online submissions
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
#define ll long long
typedef pair<int, int> PII;
ll mod = 1e9+7;
const int MX = 1e4+1;


class Solution {
public:
    vector<string> braceExpansionII(string expression) {

    }
};

int main() {
    Solution s;
    string exp = "{a{x,ia,o}w,{n,{g,{u,o}},{a,{x,ia,o},w}},er}";
    vector<string> res = s.braceExpansionII(exp);
    vector<int> nums{-1,0,1,0,3,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    ll dp[2][2][4] = {0};
    dp[1][1][1] = 3;
    memset(dp, 0, sizeof(dp));
}