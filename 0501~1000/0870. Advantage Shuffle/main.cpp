/**
 * Source: is.gd/8Ival1
 * Date: 2023/12/1
 * Skill:
 * Ref:
 * Runtime: 160 ms, faster than 56.14% of C++ online submissions
 * Memory Usage: 75.44 MB, less than 25.15% of C++ online submissions
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
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> nums(begin(nums1), end(nums1));
        vector<int> res;
        for (auto &i: nums2) {
            auto iter = nums.upper_bound(i);
            if (iter == end(nums)) {
                res.push_back(*begin(nums));
                nums.erase(begin(nums));
            } else {
                res.push_back(*iter);
                nums.erase(iter);
            }
        }
        return res;
    }
};