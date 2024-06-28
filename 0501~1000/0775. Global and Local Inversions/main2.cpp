/**
 * Source: ibit.ly/mJGHb
 * Date: 2024/6/28
 * Skill:
 * Ref:
 * Runtime: 98 ms, faster than 63.13% of C++ online submissions
 * Memory Usage: 85.74 MB, less than 60.16% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), prevMax = -1;
        for (int i = 2; i < n; i++) {
            prevMax = max(prevMax, nums[i-2]);
            if (prevMax > nums[i]) {
                return false;
            }
        }
        return true;
    }
};