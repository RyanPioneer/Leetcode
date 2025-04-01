/**
 * Source: t.ly/nbrda
 * Date: 2025/3/23
 * Skill:
 * Ref:
 * Runtime: 248 ms, faster than 50.13% of C++ online submissions
 * Memory Usage: 221.27 MB, less than 31.68% of C++ online submissions
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
#define ll long long

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries)
    {
        vector<int> res;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
        for (auto it = m.begin(); it != m.end();) {
            if (it->second.size() == 1) {
                it = m.erase(it); // 正確做法：erase 會回傳下一個有效的 iterator
            } else {
                sort(it->second.begin(), it->second.end());
                it->second.push_back(*it->second.begin() + nums.size());
                ++it;
            }
        }

        for (auto i : queries) {
            int num = nums[i];
            if (m.find(num) == m.end() || m[num].size() == 1) {
                res.push_back(-1);
            } else {
                auto lo = lower_bound(m[num].begin(), m[num].end(), i);
                int r = *next(lo) - i;
                if (lo != begin(m[num])) {
                    r = min(r, i - *prev(lo));
                } else {
                    r = min(r, int(i + nums.size() - *prev(prev(m[num].end()))));
                }
                res.push_back(r);
            }
        }
        return res;
    }
};
