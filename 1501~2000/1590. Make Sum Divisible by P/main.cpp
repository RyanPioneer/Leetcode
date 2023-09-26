/**
 * Source: t.ly/Lzt-m
 * Date: 2023/9/23
 * Skill:
 * Runtime: 135 ms, faster than 89.32% of C++ online submissions
 * Memory Usage: 66.75 MB, less than 55.68% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums.length <= 10 ** 5
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
    int minSubarray(vector<int>& nums, int p) {
        ll total = 0;
        for (auto i: nums)
            total += i;
        if (total < p)
            return -1;
        if (total % p == 0)
            return 0;
        total %= p;
        int res = nums.size(), sz = nums.size();
        ll cur_sum = 0;
        unordered_map<int, int> num2pos;
        num2pos[0] = -1;
        for (int i = 0; i < sz; i++) {
            cur_sum = (cur_sum + nums[i]) % p;
            int target = (cur_sum - total + p) % p;
            if (num2pos.find(target) != num2pos.end())
                res = min(res, i - num2pos[target]);
            num2pos[cur_sum] = i;
        }
        return res == sz ? -1 : res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}