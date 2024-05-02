/**
 * Source: t.ly/ocgdV
 * Date: 2024/5/2
 * Skill:
 * Ref:
 * Runtime: 107 ms, faster than 81.82% of C++ online submissions
 * Memory Usage: 86.70 MB, less than 88.18% of C++ online submissions
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
    int kEmptySlots(vector<int>& bulbs, int k) {
        int res = INT32_MAX, n = bulbs.size(), left = 0;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[bulbs[i] - 1] = i + 1;
        }
        while (left + k + 1 < n) {
            bool check = true;
            for (int i = 1; i <= k; i++) {
                if (nums[left + i] < nums[left] || nums[left + i] < nums[left + k + 1]) {
                    left = left + i;
                    check = false;
                    break;
                }
            }
            if (check) {
                res = min(res, max(nums[left], nums[left + k + 1]));
                left += k + 1;
            }
        }
        return res != INT32_MAX ? res : -1;
    }
};