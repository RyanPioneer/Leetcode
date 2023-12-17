/**
 * Source: jpeg.ly/vLw61
 * Date: 2023/12/17
 * Skill:
 * Ref:
 * Runtime: 105 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 75.1 MB, less than 100.00% of C++ online submissions
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
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        for (int i = 2; i < nums.size(); i += 3) {
            if (nums[i] - nums[i - 2] > k) return {};
            res.push_back({nums[i - 2], nums[i - 1], nums[i]});
        }
        return res;
    }
};