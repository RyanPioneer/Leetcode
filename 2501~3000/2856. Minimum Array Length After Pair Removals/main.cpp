/**
 * Source: https://rb.gy/eek5t
 * Date: 2023/9/17
 * Skill:
 * Runtime: 166 ms, faster than 12.50% of C++ online submissions
 * Memory Usage: 164.16 MB, less than 87.50% of C++ online submissions
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
    int minLengthAfterRemovals(vector<int>& nums) {
        int sz = nums.size();
        unordered_map<int, int> cnt;
        for (auto i: nums)
            cnt[i]++;
        for (auto i: cnt)
            if (i.second * 2 > sz)
                return sz - (sz - i.second) * 2;
        return sz % 2 == 0 ? 0 : 1;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}