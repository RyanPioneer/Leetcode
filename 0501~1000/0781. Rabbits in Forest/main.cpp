/**
 * Source: ibit.ly/BYAG4
 * Date: 2024/6/28
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 11.70 MB, less than 59.01% of C++ online submissions
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
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for (auto &i: answers) {
            mp[i]++;
        }
        int res = 0;
        for (auto &i: mp) {
            res += ((i.second - 1) / (i.first + 1) + 1) * (i.first + 1);
        }
        return res;
    }
};