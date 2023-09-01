/**
 * Source: https://rb.gy/bwbji
 * Date: 2023/9/1
 * Skill:
 * Runtime: 787 ms, faster than 5.83% of C++ online submissions
 * Memory Usage: 140.01 MB, less than 39.91% of C++ online submissions
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
        vector<vector<ll>> heap{{presum[sz], sz - 1}};
        make_heap(begin(heap), end(heap));
        for (auto i: removeQueries) {
            auto pos = pos_with_length.lower_bound(i);
            if (pos->second == 1)
                pos_with_length.erase(pos);
            else {
                int prev_length = pos->first - i, new_length = pos->second - prev_length - 1;
                pos_with_length[pos->first] = prev_length;
                if (new_length > 0) {
                    pos_with_length[i - 1] = new_length;
                    heap.push_back({presum[i] - presum[i - new_length], i - 1});
                    push_heap (heap.begin(),heap.end());
                }
                heap.push_back({presum[pos->first + 1] - presum[i + 1], pos->first });
                push_heap (heap.begin(),heap.end());
            }
            while (heap.size() > 0 && presum[heap.front()[1] + 1] - presum[heap.front()[1] - pos_with_length[heap.front()[1]] + 1] != heap.front()[0]) {
                pop_heap (heap.begin(),heap.end());
                heap.pop_back();
            }
            if (heap.size() > 0)
                res.push_back(heap.front()[0]);
            else
                res.push_back(0);
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
