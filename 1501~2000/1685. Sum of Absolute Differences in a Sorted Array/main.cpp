/**
 * Source: is.gd/sGfJKV
 * Date: 2023/11/25
 * Skill:
 * Ref:
 * Runtime: 88 ms, faster than 76.22% of C++ online submissions
 * Memory Usage: 87.82 MB, less than 30.54% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int larger = accumulate(begin(nums), end(nums), 0), smaller = 0;
        int sz = SZ(nums);
        vector<int> res;
        for (int i = 0; i < sz; ++i) {
            larger -= nums[i];
            int diff = larger - nums[i] * (sz - i - 1);
            diff += nums[i] * i - smaller;
            smaller += nums[i];
            res.push_back(diff);
        }
        return res;
    }
};