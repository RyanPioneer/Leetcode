/**
 * Source: https://rb.gy/b3nfd
 * Date: 2023/9/3
 * Skill:
 * Runtime: 171 ms, faster than 70.00% of C++ online submissions
 * Memory Usage: 117.81 MB, less than 40.00% of C++ online submissions
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
        unordered_map<int, int> mymap;
        mymap[0] = 1;
        ll res = 0, num = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % modulo == k)
                num++;
            num %= modulo;
            res += mymap[(modulo + num - k) % modulo];
            mymap[num]++;
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

}