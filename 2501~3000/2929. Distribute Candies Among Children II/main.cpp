/**
 * Source: t.ly/5T3O_
 * Date: 2023/11/12
 * Skill:
 * Runtime: 29 ms, faster than 66.67% of C++ online submissions
 * Memory Usage: 6.50 MB, less than 33.33% of C++ online submissions
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

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if (limit * 3 < n) return 0;
        if (limit * 3 == n) return 1;
        ll res = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i > limit * 2) continue;
            int num = n - i;
            int lo = max(0, num - limit);
            res += (min(limit, num) - lo + 1);
        }
        return res;
    }
};


int main() {
    Solution s;
}