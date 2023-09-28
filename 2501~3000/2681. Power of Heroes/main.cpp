/**
 * Source: ibit.ly/4C0Xt
 * Date: 2023/9/27
 * Skill:
 * Runtime: 86 ms, faster than 63.41% of C++ online submissions
 * Memory Usage: 93.52 MB, less than 17.98% of C++ online submissions
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
public:
    int sumOfPower(vector<int>& nums) {
        sort(begin(nums), end(nums));
        ll res = 0, pre = 0, mod = 1e9+7;
        for (int i = 0; i < nums.size(); i++) {
            res = (res + (pre + nums[i]) % mod * (ll)nums[i] % mod *(ll)nums[i] % mod) % mod;
            pre = (pre * 2 % mod + nums[i]) % mod;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {2, 10},
                             {1, 10},
                             {2, 3},
                             {6,10},
                             {4,3},
                             {8,6},
                             {5,8},
                             {7,6}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}