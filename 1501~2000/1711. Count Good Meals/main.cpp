/**
 * Source: https://rb.gy/13wjv
 * Date: 2023/9/4
 * Skill:
 * Runtime: 490 ms, faster than 54.13% of C++ online submissions
 * Memory Usage: 125.47 MB, less than 28.35% of C++ online submissions
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
    int countPairs(vector<int>& deliciousness) {
        ll mod = 1e9+7, res = 0;
        unordered_map<int, int> num2count;
        for (auto num: deliciousness) {
            for (int i = (1 << 21); i > 0; i >>= 1) {
                if (i < num)
                    break;
                res += num2count[i - num];
                res %= mod;
            }
            num2count[num]++;
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
    vector<int> v1{1,2,1,2,1,2}, v2{2,1,1,2,2,1};
}