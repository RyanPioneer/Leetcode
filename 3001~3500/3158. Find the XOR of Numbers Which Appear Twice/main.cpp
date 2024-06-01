/**
 * Source: t.ly/lzm7B
 * Date: 2024/5/26
 * Skill:
 * Ref:
 * Runtime: 7 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 27.70 MB, less than 40.00% of C++ online submissions
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
const int MX = 1e5+7;


class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        for (auto &i: nums) {
            mp[i]++;
        }
        for (auto &i: mp) {
            if (i.second == 2) {
                res ^= i.first;
            }
        }
        return res;
    }
};