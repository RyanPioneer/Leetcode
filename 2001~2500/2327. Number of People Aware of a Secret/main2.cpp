/**
 * Source: tinyurl.com/ynurzkqb
 * Date: 2023/10/20
 * Skill:
 * Runtime: 4 ms, faster than 75.49% of C++ online submissions
 * Memory Usage: 7.62 MB, less than 8.08% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= n <= 1000
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
    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll mod = 1e9+7, res = 0;
        vector<ll> new_people(n + 1, 0), diff(n + 1, 0);
        diff[1] = 1, diff[2] = -1;
        for (int i = 1; i <= n; i++) {
            new_people[i] = (new_people[i - 1] + diff[i] + mod) % mod;
            if (i + delay <= n)
                diff[i + delay] += new_people[i];
            if (i + forget <= n)
                diff[i + forget] -= new_people[i];
        }
        for (int i = max(1, n - forget + 1); i <= n; i++)
            res = (res + new_people[i]) % mod;
        return res;
    }
};


int main() {
    Solution s;
    int res = s.peopleAwareOfSecret(6,2,5);
    vector<int> nums{5,4,6};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}