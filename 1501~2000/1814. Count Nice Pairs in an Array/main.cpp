/**
 * Source: https://rb.gy/vekhv
 * Date: 2023/9/15
 * Skill:
 * Runtime: 89 ms, faster than 84.71% of C++ online submissions
 * Memory Usage: 56.92 MB, less than 35.63% of C++ online submissions
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
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int>num2cnt;
        int res = 0, mod = 1e9+7;
        for (auto n: nums) {
            int n1 = n, n2 = 0;
            while (n > 0) {
                n2 *= 10;
                n2 += n % 10;
                n /= 10;
            }
            res = (res + num2cnt[n1 - n2]) % mod;
            num2cnt[n1 - n2]++;
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
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
}