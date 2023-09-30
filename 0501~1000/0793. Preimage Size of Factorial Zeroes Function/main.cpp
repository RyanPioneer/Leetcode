/**
 * Source: ibit.ly/bn1Jh
 * Date: 2023/9/30
 * Skill:
 * Runtime: 2 ms, faster than 53.61% of C++ online submissions
 * Memory Usage: 6.24 MB, less than 21.13% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int preimageSizeFZF(int k) {
        ll lo = 0, hi = 5e9;
        while (lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            int num = helper(mid);
            if (num > k)
                hi = mid - 1;
            else
                lo = mid;
        }
        if (helper(lo) != k)
            return 0;
        int res = 1;
        while (--lo >= 0 && helper(lo) == k)
            res++;
        return res;
    }
    int helper(ll num) {
        ll res = 0, base = 5;
        while (num >= base) {
            res += num / base;
            base *= 5;
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
    ll a = 5e9;
    cout << 1e9 << endl;
    cout << a << endl;
}