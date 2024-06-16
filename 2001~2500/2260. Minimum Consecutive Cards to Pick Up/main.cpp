/**
 * Source: t.ly/OoDiR
 * Date: 2024/6/7
 * Skill:
 * Ref:
 * Runtime: 210 ms, faster than 74.22% of C++ online submissions
 * Memory Usage: 118.82 MB, less than 41.86% of C++ online submissions
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
    int minimumCardPickup(vector<int>& cards) {
        int res = INT32_MAX;
        unordered_map<int, int> mp;
        for (int i = 1; i <= cards.size(); i++) {
            if (mp[cards[i-1]] != 0) {
                res = min(res, i - mp[cards[i-1]] + 1);
            }
            mp[cards[i-1]] = i;
        }
        return res != INT32_MAX ? res : -1;
    }
};