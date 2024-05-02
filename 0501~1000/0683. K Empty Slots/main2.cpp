/**
 * Source: t.ly/ocgdV
 * Date: 2024/5/2
 * Skill:
 * Ref:
 * Runtime: 144 ms, faster than 49.09% of C++ online submissions
 * Memory Usage: 93.11 MB, less than 13.64% of C++ online submissions
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
        set<int> nums;

        for (int i = 1; i <= bulbs.size(); i++) {
            auto it = nums.upper_bound(bulbs[i - 1]);
            if (it != end(nums) && *it - bulbs[i - 1] == k + 1) {
                return i;
            }
            if (it != begin(nums) && bulbs[i - 1] - *prev(it) == k + 1) {
                return i;
            }
            nums.insert(bulbs[i - 1]);
        }
        return -1;
    }
};