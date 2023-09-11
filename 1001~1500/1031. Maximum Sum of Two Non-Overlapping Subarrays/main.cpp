/**
 * Source: https://rb.gy/1s63n
 * Date: 2023/9/11
 * Skill:
 * Runtime: 3 ms, faster than 86.61% of C++ online submissions
 * Memory Usage: 8.48 MB, less than 77.69% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(get_max(nums, firstLen, secondLen), get_max(nums, secondLen, firstLen));
    }
    int get_max(vector<int>& nums, int firstLen, int secondLen) {
        int first_max = 0, second_max = 0, sz = nums.size();
        for (int i = 0; i < firstLen + secondLen; i++) {
            if (i < firstLen)
                first_max += nums[i];
            else
                second_max += nums[i];
        }
        int cur_first = first_max, res = first_max + second_max;
        for (int i = firstLen + secondLen; i < sz; i++) {
            second_max += nums[i] - nums[i - secondLen];
            cur_first += nums[i - secondLen] - nums[i - secondLen - firstLen];
            first_max = max(first_max, cur_first);
            res = max(res, second_max + first_max);
        }
        return res;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
}