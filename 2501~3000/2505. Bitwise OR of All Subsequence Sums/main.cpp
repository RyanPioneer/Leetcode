/**
 * Source: ibit.ly/UWlKr
 * Date: 2024/5/18
 * Skill:
 * Ref:
 * Runtime: 86 ms, faster than 35.70% of C++ online submissions
 * Memory Usage: 54.61 MB, less than 36.19% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        ll res = 0;
        For(i,0,61) {
            ll cur = 0, target = 1ll<<i;
            for (auto &j: nums) {
                cur += j % (target * 2);
                if (cur >= target) break;
            }
            if (cur >= target) res |= target;
        }
        return res;
    }
};