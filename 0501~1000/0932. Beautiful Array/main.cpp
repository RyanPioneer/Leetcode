/**
 * Source: t.ly/YCCKm
 * Date: 2024/6/1
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 21.54% of C++ online submissions
 * Memory Usage: 16.26 MB, less than 25.08% of C++ online submissions
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


class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};
        vector<int> res;
        vector<int> odd = beautifulArray((n + 1) / 2);
        vector<int> even = beautifulArray(n - (n + 1) / 2);
        for (auto &i: odd) res.push_back(i * 2 - 1);
        for (auto &i: even) res.push_back(i * 2);
        return res;
    }
};