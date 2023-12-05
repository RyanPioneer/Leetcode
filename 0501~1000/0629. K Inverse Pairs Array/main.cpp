/**
 * Source: is.gd/DvkYMZ
 * Date: 2023/12/5
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 79.80% of C++ online submissions
 * Memory Usage: 6.23 MB, less than 99.01% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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
#define ll long long
ll mod = 1e9+7;
const int MX = 1001;


class Solution {
public:
    int kInversePairs(int n, int k) {
        ll cnt[MX] = {0}, presum[MX] = {0};
        cnt[0] = presum[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) presum[j] = (presum[j - 1] + cnt[j]) % mod;
            for (int j = k; j >= 1; j--) {
                if (j - i - 1 >= 0) cnt[j] = (presum[j] - presum[j - i - 1]) % mod;
                else cnt[j] = presum[j] % mod;
            }
        }
        return (cnt[k] + mod) % mod;
    }
};