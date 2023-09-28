/**
 * Source: ibit.ly/2ChuX
 * Date: 2023/9/28
 * Skill:
 * Runtime: 6 ms, faster than 71.20% of C++ online submissions
 * Memory Usage: 16.63 MB, less than 18.22% of C++ online submissions
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
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] % 2 == 0)
                swap(nums[even++], nums[i]);
        return nums;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {7,6}};
}