/**
 * Source: ibit.ly/RgEMP
 * Date: 2023/10/3
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.47 MB, less than 27.67% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums[i] <= 100
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
    int numIdenticalPairs(vector<int>& nums) {
        int cnt[101] = {0}, res = 0;
        for (auto i: nums)
            cnt[i]++;
        for (int i = 1; i <= 100; i++)
            if (cnt[i] > 1)
                res += cnt[i] * (cnt[i] - 1) / 2;
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}