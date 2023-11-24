/**
 * Source: is.gd/AC4i88
 * Date: 2023/11/24
 * Skill:
 * Ref:
 * Runtime: 828 ms, faster than 72.64% of C++ online submissions
 * Memory Usage: 8.34 MB, less than 92.45% of C++ online submissions
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
#define MK(X, Y) make_pair(X, Y)
typedef pair<char, char> PCC;


class Solution {
    map<PCC, vector<char>> mp;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &i: allowed) {
            mp[{i[0], i[1]}].push_back(i[2]);
        }
        return dfs(bottom, "", 1);
    }
    bool dfs(string bottom, string next, int idx) {
        if (bottom.length() == 1) return true;
        if (idx == bottom.length()) return dfs(next, "", 1);
        PCC p = MK(bottom[idx - 1], bottom[idx]);
        if (mp.find(p) == end(mp)) return false;
        for (auto c: mp[p]) {
            if (next.length() == 0 || mp.find(MK(next.back(), c)) != end(mp)) {
                next.push_back(c);
                if (dfs(bottom, next, idx + 1)) return true;
                next.pop_back();
            }
        }
        return false;
    }
};