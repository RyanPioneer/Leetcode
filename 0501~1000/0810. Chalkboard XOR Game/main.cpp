/**
 * Source: ibit.ly/EYjfz
 * Date: 2023/9/29
 * Skill:
 * Runtime: 3 ms, faster than 96.00% of C++ online submissions
 * Memory Usage: 13.50 MB, less than 11.00% of C++ online submissions
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
    bool xorGame(vector<int>& nums) {
        int num = 0;
        for (auto n: nums)
            num ^= n;
        return num == 0 || nums.size() % 2 == 0;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}