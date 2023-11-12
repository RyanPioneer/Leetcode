/**
 * Source: t.ly/SG59J
 * Date: 2023/11/12
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.42 MB, less than 100.00% of C++ online submissions
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
    int stringCount(int n) {
        if (n < 4) return 0;
        ll mod = 1e9+7, res = 0, full = 1, part1 = 1, part2 = 1, part3 = 1, part4 = 1, part5 = 1, part6 = 1;
        for (int i = 1; i <= n; i++) {
            full = full * 26 % mod;
            part1 = part1 * 25 % mod;
            part2 = part2 * 24 % mod;
            part3 = part3 * 23 % mod;
            if (i < n) {
                part4 = part4 * 25 % mod;
                part5 = part5 * 24 % mod;
                part6 = part6 * 23 % mod;
            }
        }
        res = full - part1 * 3 - part4 * n + part2 + 2 * (part2 + part5 * n) - part3 - part6 * n;
        while (res < 0) res += mod;
        return (res + mod) % mod;
    }
};


int main() {
    Solution s;
}