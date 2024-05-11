/**
 * Source: t.ly/c6h5i
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 252 ms, faster than 33.33% of C++ online submissions
 * Memory Usage: 99.99 MB, less than 100.00% of C++ online submissions
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


#define ll long long
using namespace std;

const int MX = 1e5+2;


class Solution {
public:
    vector<long long> minimumRelativeLosses(vector<int>& prices, vector<vector<int>>& queries) {
        sort(begin(prices), end(prices));
        vector<long long> res;
        ll presum[MX] = {0};
        int n = prices.size();
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + prices[i - 1];
        }
        for (auto &q: queries) {
            if (q[1] == n) {
                int pos = upper_bound(begin(prices), end(prices), q[0]) - begin(prices);
                ll i = presum[pos] + (ll)q[0] * (n - pos) * 2 - (presum[n] - presum[pos]);
                res.push_back(i);
                continue;
            }
            int left = 0, right = q[1], n2 = n - q[1];
            while (left < right) {
                int mid = (left + right) / 2;
                int r = mid + n2;
                if (r < n) {
                    int n1 = prices[r] <= q[0] ? prices[r] : 2 * q[0] - prices[r];
                    int n2 = prices[mid] <= q[0] ? prices[mid] : 2 * q[0] - prices[mid];
                    if (n1 > n2) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                } else {
                    right = mid;
                }
            }
            int pos = upper_bound(begin(prices), end(prices), q[0]) - begin(prices);
            ll num = 0;
            right = left + n2;
            if (left > 0 && pos > 0) {
                num += presum[min(pos, left)];
            }
            if (right < pos) {
                num += presum[pos] - presum[right + 1];
            }
            ll cnt = n - max(right, pos);
            num += (ll)q[0] * cnt * 2 - (presum[n] - presum[max(right, pos)]);
            res.push_back(num);
        }
        return res;
    }
};