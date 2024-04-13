/**
 * Source: is.gd/eYj4LH
 * Date: 2024/4/7
 * Skill:
 * Ref:
 * Runtime: 15 ms, faster than 76.63% of C++ online submissions
 * Memory Usage: 20.92 MB, less than 94.27% of C++ online submissions
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

const int MOD = 1e9+7, MX = 1e2+10;


class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        ll res = 0, carry[MX] = {1}, cnt[MX][MX] = {0};
        cnt[0][0] = 1;
        for (int i = 1; i < MX; i++) carry[i] = carry[i - 1] * 2 % MOD;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            res = res * 2 % MOD;
            if (k >= nums[i]) {
                for (int j = 0; j <= i; j++) {
                    res = (res + carry[i - j] * cnt[k - nums[i]][j] % MOD) % MOD;
                }
                for (int j = k; j >= nums[i]; j--) {
                    for (int l = 0; l <= i; l++) {
                        cnt[j][l + 1] = (cnt[j][l + 1] + cnt[j - nums[i]][l]) % MOD;
                    }
                }
            }
        }
        return res;
    }
};