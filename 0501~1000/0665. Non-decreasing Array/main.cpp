/**
 * Source: ibit.ly/ox1HI
 * Date: 2023/10/4
 * Skill:
 * Runtime: 19 ms, faster than 66.43% of C++ online submissions
 * Memory Usage: 27.50 MB, less than 13.20% of C++ online submissions
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
    bool checkPossibility(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] > nums[i + 1]) {
                if (i == 0 || nums[i - 1] <= nums[i + 1])
                    nums[i] = nums[i + 1];
                else
                    nums[i + 1] = nums[i];
                num++;
                if (num > 1)
                    return false;
            }
        return true;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}