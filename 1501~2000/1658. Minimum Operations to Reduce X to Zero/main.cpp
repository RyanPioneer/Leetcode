/**
 * Source: t.ly/GOihx
 * Date: 2023/9/20
 * Skill:
 * Runtime: 301 ms, faster than 25.32% of C++ online submissions
 * Memory Usage: 151.92 MB, less than 22.91% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> sum2idx;
        sum2idx[0] = -1;
        int res = INT32_MAX, sz = nums.size(), cur_sum = 0;
        int target = accumulate(begin(nums), end(nums), -x);
        if (target == 0)
            return sz;
        if (target < 0)
            return -1;
        for (int i = 0; i < sz; i++) {
            cur_sum += nums[i];
            if (sum2idx.find(cur_sum - target) != sum2idx.end())
                res = min(res, sz - (i - sum2idx[cur_sum - target]));
            sum2idx[cur_sum] = i;
        }
        return res != INT32_MAX ? res : -1;
    }
};

int main() {

}