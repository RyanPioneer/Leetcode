/**
 * Source: tinyurl.com/ykekz9fr
 * Date: 2023/10/22
 * Skill:
 * Runtime: 64 ms, faster than 98.74% of C++ online submissions
 * Memory Usage: 54.37 MB, less than 35.22% of C++ online submissions
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
#include <bitset>
#include <functional>
#include <list>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        function<ll(ll)> get_reverse_num;
        get_reverse_num = [=](ll num) {
            ll n = 0;
            while (num > 0) {
                n *= 10;
                n += num % 10;
                num /= 10;
            }
            return n;
        };
        vector<ll> res;
        ll num = pow(10, intLength / 2 - 1), is_odd = (intLength % 2 == 1 ? 10 : 1);
        ll mid_base = pow(10, intLength / 2), head_base = pow(10, intLength / 2 + intLength % 2);
        ll limit = (intLength == 1 ? 9 : max(num, 1ll) * 9 * is_odd);
        for (auto q: queries) {
            if (q > limit)
                res.push_back(-1);
            else {
                if (intLength == 1) {
                    res.push_back(q);
                    continue;
                }
                q -= 1;
                ll head = num + (is_odd == 1 ? q : q / 10);
                ll mid = (is_odd == 1 ? 0 : q % 10);
                ll tail = get_reverse_num(head);
                res.push_back(tail + mid * mid_base + head * head_base);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{89135};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}