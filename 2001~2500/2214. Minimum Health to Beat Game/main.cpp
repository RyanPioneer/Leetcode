/**
 * Source: t.ly/jrnSR
 * Date: 2024/6/6
 * Skill:
 * Ref:
 * Runtime: 70 ms, faster than 57.33% of C++ online submissions
 * Memory Usage: 61.48 MB, less than 94.67% of C++ online submissions
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


class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        ll total = 0, mx = 0;
        for (auto &d: damage) {
            total += d;
            mx = max((ll)d, mx);
        }
        mx = mx <= armor ? mx : armor;
        return total - mx + 1;
    }
};