/**
 * Source: jpeg.ly/HzDPG
 * Date: 2024/1/21
 * Skill:
 * Ref:
 * Runtime: 15 ms, faster than 83.33% of C++ online submissions
 * Memory Usage: 32.23 MB, less than 33.33% of C++ online submissions
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
    bool canSortArray(vector<int>& nums) {
        set<int> n;
        for (auto &i: nums) {
            auto it = n.upper_bound(i);
            while (it != end(n)) {
                if (__builtin_popcount(i) != __builtin_popcount(*it)) return false;
                it = next(it);
            }
            n.insert(i);
        }
        return true;
    }
};