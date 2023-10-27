/**
 * Source: tinyurl.com/yvr8b8jp
 * Date: 2023/10/27
 * Skill:
 * Runtime: 196 ms, faster than 74.70% of C++ online submissions
 * Memory Usage: 183.80 MB, less than 89.96% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums[i] <= 30
 *      1 <= nums.length <= 10 ** 5
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
#include <bitset>
#include <functional>
#include <list>

using namespace std;

#define ll unsigned long long

const int MX = 31;
int valid_num[MX];
int init = []() {
    for (int i = 0; i < MX; i++) valid_num[i] = 1;
    for (int i = 2; i <= sqrt(MX); i++) {
        int j = i * i;
        while (j < MX) {
            valid_num[j] = 0;
            j += i * i;
        }
    }
    return 0;
}();

class Solution {
    ll mod = 1e9+7;
    ll multiple_two(int time) {
        if (time == 0) return 1;
        if (time == 1) return 2;
        ll num = multiple_two(time / 2);
        return num % mod * num % mod * ((time % 2) == 1 ? 2 : 1) % mod;
    }
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int cnt[31] = {0};
        ll res = 0, mx = *max_element(begin(nums), end(nums));
        for (auto i: nums) cnt[i]++;
        function<void(int, int, ll)> dfs;
        dfs = [&](int idx, ll cur_product, ll total) {
            if (idx == mx + 1) {
                if (cur_product > 1) res = (res + total) % mod;
                return;
            }
            dfs(idx + 1, cur_product, total);
            if (valid_num[idx] == 1 && gcd(idx, cur_product) == 1) {
                dfs(idx + 1, cur_product * idx, total * cnt[idx] % mod);
            }
        };
        dfs(2, 1, 1);
        return res % mod * multiple_two(cnt[1]) % mod;
    }
};


int main() {
//    Solution s;
}