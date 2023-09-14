/**
 * Source: https://rb.gy/7cpqr
 * Date: 2023/9/14
 * Skill:
 * Runtime: 32 ms, faster than 45.47% of C++ online submissions
 * Memory Usage: 18.84 MB, less than 11.15% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


typedef pair<int, int> pairs;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        map<int, vector<pairs>> pos2height;
        for (auto i: buildings) {
            pos2height[i[0]].push_back(make_pair(i[2], 1));
            pos2height[i[1]].push_back(make_pair(i[2], 0));
        }
        multiset<int> sets;
        for (auto p: pos2height) {
            for (auto i: p.second) {
                if (i.second)
                    sets.insert(i.first);
                else
                    sets.erase(sets.find(i.first));
            }
            int h = sets.empty() ? 0 : *sets.rbegin();
            if (res.empty() || h != res.back()[1])
                res.push_back({p.first, h});
        }
        return res;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<vector<int>> res = s.getSkyline(arr);
    for (auto i: res)
        cout << i[0] << " " << i[1] << " " << endl;
}