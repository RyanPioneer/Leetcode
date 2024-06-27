/**
 * Source: ibit.ly/iiuJc
 * Date: 2024/6/23
 * Skill:
 * Ref:
 * Runtime: 113 ms, faster than 88.89% of C++ online submissions
 * Memory Usage: 154.99 MB, less than 66.67% of C++ online submissions
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
        int n = nums.size(), curNum = nums.back(), res = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] != curNum) {
                res++;
                curNum = nums[i];
            }
        }
        return res + (curNum == 0);
    }
};