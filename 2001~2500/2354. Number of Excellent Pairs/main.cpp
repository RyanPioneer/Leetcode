/**
 * Source: https://rb.gy/luenp
 * Date: 2023/8/29
 * Skill:
 * Runtime: 377 ms, faster than 43.02% of C++ online submissions
 * Memory Usage: 98.39 MB, less than 51.32% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define ll long long
// using ll = long long;


class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        ll res = 0;
        vector<int> count(32, 0), presum(33, 0);
        unordered_set<int> myset(nums.begin(), nums.end());
        for (auto i: myset)
            count[__builtin_popcount(i)] += 1;
        int total = myset.size();
        for (int i = 0; i < 32; i++)
            presum[i + 1] = presum[i] + count[i];
        for (int i = 0; i < 32; i++) {
            int j = k - i;
            if (j <= i)
                res += (total - presum[i + 1]) * count[i] * 2 + count[i] * count[i];
            else if (j < 32){
                res += (total - presum[j]) * count[i] * 2;
            }
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
    int k = 3;
    int res = s.countExcellentPairs(tasks, k);
    cout << res << endl;
}