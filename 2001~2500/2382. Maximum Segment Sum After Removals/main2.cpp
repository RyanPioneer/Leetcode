/**
 * Source: https://rb.gy/bwbji
 * Date: 2023/9/1
 * Skill:
 * Runtime: 374 ms, faster than 42.60% of C++ online submissions
 * Memory Usage: 140.93 MB, less than 39.46% of C++ online submissions
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
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int sz = nums.size();
        vector<ll> presum(sz + 1, 0), res;
        for (int i = 0; i < sz; i++)
            presum[i + 1] = nums[i] + presum[i];
        map<int, int> pos_with_length;
        pos_with_length[sz - 1] = sz;
        multiset<ll> myset;
        myset.insert(0);
        myset.insert(presum[sz]);
        for (auto i: removeQueries) {
            auto pos = pos_with_length.lower_bound(i);
            if (pos->second == 1) {
                pos_with_length.erase(pos);
                myset.erase(myset.lower_bound(nums[i]));
            } else {
                int prev_length = pos->first - i, new_length = pos->second - prev_length - 1;
                myset.erase(myset.lower_bound(presum[pos->first + 1] - presum[pos->first - pos->second + 1]));
                pos_with_length[pos->first] = prev_length;
                if (new_length > 0) {
                    pos_with_length[i - 1] = new_length;
                    myset.insert(presum[i] - presum[i - new_length]);
                }
                myset.insert(presum[pos->first + 1] - presum[i + 1]);
            }
            res.push_back(*myset.rbegin());
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
    vector<int> nums{1,2,5,6,1}, queries{0,3,2,4,1};
    vector<long long> res = s.maximumSegmentSum(nums, queries);
    for (auto i: res)
        cout << i << endl;
}