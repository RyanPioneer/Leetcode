/**
 * Source: ibit.ly/ril3b
 * Date: 2023/9/27
 * Skill:
 * Runtime: 225 ms, faster than 16.21% of C++ online submissions
 * Memory Usage: 84.1 MB, less than 98.42% of C++ online submissions
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
    long long maximumOr(vector<int>& nums, int k) {
        ll res = 0, total = 0;
        int cnt[32] = {0};
        for (auto n: nums) {
            total |= n;
            for (int i = 0; i < 32; i++)
                if (((n >> i) & 1) != 0)
                    cnt[i]++;
        }
        for (auto n: nums) {
            ll num = total;
            for (int i = 0; i < 32; i++)
                if (((n >> i) & 1) != 0 && cnt[i] == 1)
                    num -= (1 << i);
            res = max(res, num | ((ll)n << k));
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