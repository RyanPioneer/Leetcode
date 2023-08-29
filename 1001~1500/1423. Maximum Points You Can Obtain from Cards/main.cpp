/**
 * Source: https://rb.gy/8kmu5
 * Date: 2023/8/29
 * Skill:
 * Runtime: 43 ms, faster than 85.78% of C++ online submissions
 * Memory Usage: 42.42 MB, less than 29.31% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ll long long
// using ll = long long;


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        ll total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        ll cur_sum = 0, sz = cardPoints.size();
        for (int i = 0; i < sz - k; i++)
            cur_sum += cardPoints[i];
        ll res = total - cur_sum;
        for (int i = sz - k; i < sz; i++) {
            cur_sum += cardPoints[i] - cardPoints[i - (sz - k)];
            res = max(res, total - cur_sum);
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
    vector<int> tasks{1,2,3,1};
}