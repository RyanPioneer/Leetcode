/**
 * Source: ibit.ly/Ltfgx
 * Date: 2024/6/24
 * Skill:
 * Ref:
 * Runtime: 119 ms, faster than 60.00% of C++ online submissions
 * Memory Usage: 138.40 MB, less than 60.00% of C++ online submissions
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
    int minOperations(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                for (int j = 0; j < 3; j++) {
                    nums[i+j] = 1 - nums[i+j];
                }
                res++;
            }
        }
        if (nums[n-2] == 0 || nums[n-1] == 0) return -1;
        return res;
    }
};