/**
 * Source: ibit.ly/uNINK
 * Date: 2023/9/27
 * Skill:
 * Runtime: 94 ms, faster than 87.51% of C++ online submissions
 * Memory Usage: 48.5 MB, less than 22.48% of C++ online submissions
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
    int matrixSum(vector<vector<int>>& nums) {
        int res = 0, m = nums.size(), n = nums[0].size();
        for (int i = 0; i < m; i++)
            sort(begin(nums[i]), end(nums[i]));
        for (int i = 0; i < n; i++) {
            int num = nums[0][i];
            for (int j = 1; j < m; j++)
                num = max(num, nums[j][i]);
            res += num;
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