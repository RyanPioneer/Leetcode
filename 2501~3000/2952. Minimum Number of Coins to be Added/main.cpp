/**
 * Source: jpeg.ly/xv48i
 * Date: 2023/12/3
 * Skill:
 * Ref:
 * Runtime: 109 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 77.03 MB, less than 25.00% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define ll long long


class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int res = 0, idx = 0, sz = SZ(coins);
        ll num = 0;
        sort(begin(coins), end(coins));
        for (auto &c: coins) {
            while (num + 1 < c) {
                res++;
                num += num + 1;
            }
            num += c;
        }
        while (num < target) {
            res++;
            num += num + 1;
        }
        return res;
    }
};