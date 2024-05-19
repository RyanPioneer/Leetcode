/**
 * Source: t.ly/IJIlt
 * Date: 2024/5/19
 * Skill:
 * Ref:
 * Runtime: 86 ms, faster than 85.23% of C++ online submissions
 * Memory Usage: 79.09 MB, less than 13.64% of C++ online submissions
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
#define ll long long
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


const int MX = 1e5+10;


class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        ll dp[MX] = {0}, res = 1;
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            if (nums[i] > nums[i-1]) {
                dp[i] += dp[i-1];
            }
            res += dp[i];
        }
        return res;
    }
};