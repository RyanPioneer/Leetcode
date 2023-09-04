/**
 * Source: https://rb.gy/qhbwg
 * Date: 2023/9/2
 * Skill:
 * Runtime: 198 ms, faster than 90.30% of C++ online submissions
 * Memory Usage: 119.38 MB, less than 82.38% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= k <= nums.length <= 10 ** 5
 *      -10 ** 4 <= nums[i] <= 10 ** 4
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <numeric>
#include <tuple>
#include <deque>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int res = nums[0];
        deque<pairs> q;
        q.push_back({0, nums[0]});
        for (int i = 1; i < nums.size(); i++) {
            while (!q.empty() && q.front().first < i - k)
                q.pop_front();
            int cur_num = nums[i];
            if (q.front().second > 0)
                cur_num += q.front().second;
            while (!q.empty() && q.back().second < cur_num)
                q.pop_back();
            res = max(res, cur_num);
            q.push_back({i, cur_num});
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
    vector<int> nums{1,3,2};
//    cout << res << endl;
}