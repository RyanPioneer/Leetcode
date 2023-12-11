/**
 * Source: jpeg.ly/c1NM2
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 216 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 144.79 MB, less than 14.29% of C++ online submissions
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


const int MX = 101;


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int left = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt[nums[i]]++;
            while (cnt[nums[i]] > k) {
                cnt[nums[left++]]--;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};