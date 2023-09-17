/**
 * Source: https://rb.gy/smd4e
 * Date: 2023/9/17
 * Skill:
 * Runtime: 11 ms, faster than 66.67% of C++ online submissions
 * Memory Usage: 21.88 MB, less than 33.33% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            if (__builtin_popcount(i) == k)
                res += nums[i];
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}