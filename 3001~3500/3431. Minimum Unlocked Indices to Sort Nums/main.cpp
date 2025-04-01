/**
 * Source: t.ly/p1HNh
 * Date: 2025/1/29
 * Skill:
 * Ref:
 * Runtime: 10 ms, faster than 65.85% of C++ online submissions
 * Memory Usage: 375.80 MB, less than 7.32% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= nums.length <= 10 ** 5
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
    int minUnlockedIndices(vector<int>& nums, vector<int>& locked) {
        int n = nums.size();
        vector<int> postMin(n+1, 4);

        for (int i = n-1; i >= 0; i--) {
            postMin[i] = min(postMin[i+1], nums[i]);
        }

        int res = 0, curMax = nums[0];
        for (int i = 0; i < n; i++) {
            curMax = max(curMax, nums[i]);
            if (curMax > postMin[i] + 1) {
                return -1;
            }
            if (locked[i] == 1 && curMax > postMin[i+1]) {
                res++;
            }
        }
        return res;
    }
};
