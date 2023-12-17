/**
 * Source: is.gd/92DGNS
 * Date: 2023/12/15
 * Skill:
 * Ref:
 * Runtime: 6 ms, faster than 92.58% of C++ online submissions
 * Memory Usage: 10.91 MB, less than 71.53% of C++ online submissions
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


class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;
        for (auto &p: paths) {
            cities.insert(p[1]);
        }
        for (auto &p: paths) {
            cities.erase(p[0]);
        }
        return *cities.begin();
    }
};