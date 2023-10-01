/**
 * Source: ibit.ly/Qq4we
 * Date: 2023/10/1
 * Skill:
 * Runtime: 113 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 85.42 MB, less than 16.67% of C++ online submissions
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
    int minOperations(vector<int>& nums) {
        unordered_map<int, int>cnt;
        for (auto i: nums)
            cnt[i]++;
        int res = 0;
        for (auto i: cnt) {
            if (i.second == 1)
                return -1;
            res += i.second / 3 + (i.second % 3 != 0);
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}