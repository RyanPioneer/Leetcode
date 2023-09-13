/**
 * Source: https://rb.gy/gjn0k
 * Date: 2023/9/13
 * Skill:
 * Runtime: 94 ms, faster than 91.93% of C++ online submissions
 * Memory Usage: 83.16 MB, less than 97.98% of C++ online submissions
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
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> res;
        if (k == 1) {
            for (int i = 1; i < nums.size() - 1; i++)
                res.push_back(i);
            return res;
        }
        long long left = 1, right = 1;
        for (int i = 1; i < k - 1; i++) {
            if (nums[i] <= nums[i - 1])
                left++;
            else
                left = 1;
            if (nums[k + 1 + i] >= nums[k + i])
                right++;
            else
                right = 1;
        }
        for (int i = k; i < nums.size() - k; i++) {
            if (nums[i - 1] <= nums[i - 2])
                left++;
            else
                left = 1;
            if (nums[i + k] >= nums[i + k - 1])
                right++;
            else
                right = 1;
            if (left == k && right == k)
                res.push_back(i);
            if (nums[i - k] >= nums[i - k + 1] && left == k)
                left--;
            if (nums[i + 1] <= nums[i + 2] && right == k)
                right--;
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
    cout << 8 % -2;
}