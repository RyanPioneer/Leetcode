/**
 * Source: https://rb.gy/crf91
 * Date: 2023/9/16
 * Skill:
 * Runtime: 647 ms, faster than 48.98% of C++ online submissions
 * Memory Usage: 96.20 MB, less than 92.78% of C++ online submissions
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
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        ll lo = stoll(left), hi = stoll(right), limit = pow(10, 9);
        int start = pow(10, max(0, (int)left.length() / 4));
        int end = pow(10, (int)right.length() / 4 + 1);
        int res = 0;
        for (int i = start; i <= end; i++) {
            for (int type = 0; type < 2; type++) {
                ll palin = get_palin(i, type);
                if (palin >= limit)
                    continue;
                ll num = palin * palin;
                if (is_palin(num) && num >= lo && num <= hi)
                    res++;
            }
        }
        return res;
    }
    ll get_palin(int num, int type) {
        ll res = num;
        if (type == 0)
            num /= 10;
        while (num > 0) {
            res *= 10;
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    bool is_palin(ll num) {
        string s = to_string(num);
        string t = s;
        reverse(begin(t), end(t));
        return t == s;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}