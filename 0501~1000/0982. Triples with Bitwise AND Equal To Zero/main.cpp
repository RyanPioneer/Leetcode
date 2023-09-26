/**
 * Source: t.ly/2ftJx
 * Date: 2023/9/25
 * Skill:
 * Runtime: 149 ms, faster than 74.63% of C++ online submissions
 * Memory Usage: 7.54 MB, less than 79.60% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums.length <= 1000
 *      0 <= nums[i] < 2 ** 16
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
    int countTriplets(vector<int>& nums) {
        int cnt[1<<16] = {0}, res = 0, maximum = *max_element(begin(nums), end(nums));
        for (auto i: nums)
            for (auto j: nums)
                cnt[i & j]++;
        for (auto i: nums)
            for (int j = 0; j <= maximum; j++) {
                if ((i & j) == 0)
                    res += cnt[j];
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