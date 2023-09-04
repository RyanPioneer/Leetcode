/**
 * Source: https://rb.gy/b3nfd
 * Date: 2023/9/3
 * Skill:
 * Runtime: TLE
 * Memory Usage:
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <set>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<int> pos;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] % modulo == k)
                pos.push_back(i);
        ll res = 0, sz = pos.size(), sz2 = nums.size();
        if (k == 0) {
            if (sz == 0)
                res = sz2 * (sz2 + 1) / 2;
            else {
                res += pos[0] * (pos[0] + 1) / 2;
                for (int i = 0; i < sz - 1; i++) {
                    int length = pos[i + 1] - pos[i] - 1;
                    res += length * (length + 1) / 2;
                }
                int length = sz2 - 1 - pos[sz - 1];
                res += length * (length + 1) / 2;
            }
        }
        if (sz < k)
            return res;
        for (int i = 0; i < sz; i++) {
            int prev = pos[i] + 1;
            if (i > 0)
                prev = pos[i] - pos[i - 1];
            int l = k;
            if (k == 0)
                l = modulo;
            for (; i + l - 1 < sz; l += modulo) {
                if (i + l == sz)
                    res += prev * (nums.size() - pos[i + l - 1]);
                else
                    res += prev * (pos[i + l] - pos[i + l - 1]);
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