/**
 * Source: tinyurl.com/jsfd4l3
 * Date: 2025/4/20
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 11.06 MB, less than 82.54% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#define ull unsigned long long

class Solution {
   public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> groups;

        for (const string& str : strings) {
            int diff = str[0] - 'a';
            string key;
            for (char c : str) {
                key += (c - 'a' - diff + 26) % 26 + 'a';
            }
            groups[key].push_back(str);
        }

        for (auto& [key, group] : groups) {
            res.push_back(group);
        }

        return res;
    }
};
