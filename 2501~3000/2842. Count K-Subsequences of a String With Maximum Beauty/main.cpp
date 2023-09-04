/**
 * Source: https://rb.gy/f5xyd
 * Date: 2023/9/3
 * Skill:
 * Runtime: 43 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 12.96 MB, less than 70.00% of C++ online submissions
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
    ll mod = 1e9+7;
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        ll res = 1;
        unordered_map<int, int> char2count;
        for (auto c: s)
            char2count[c - 'a']++;
        priority_queue <int> pq;
        for (auto c: char2count)
            pq.push(c.second);
        int cur_length = INT32_MAX, cur_num = 0;
        while (cur_num < k && !pq.empty()) {
            cur_length = pq.top();
            pq.pop();
            int count = 1;
            while (!pq.empty() && pq.top() == cur_length) {
                count++;
                pq.pop();
            }
            if (count + cur_num <= k) {
                cur_num += count;
                for (int i = 0; i < count; i++)
                    res = res * cur_length % mod;
            } else {
                int space = k - cur_num;
                ll comb = nCr(count, space);
                res = res * comb * cal_mul(cur_length, space) % mod;
                return res;
            }
        }
        return cur_num == k ? res : 0;
    }
    ll nCr(int n, int r) {
        if (r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
    ll cal_mul(int n, int m) {
        ll res = 1;
        for (int i = 0; i < m; i++)
            res = res * n % mod;
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
    string ss = "jyuhiyzjuk";
    int k = 2;
    int res = s.countKSubsequencesWithMaxBeauty(ss, k);
    cout << ss << endl;
}