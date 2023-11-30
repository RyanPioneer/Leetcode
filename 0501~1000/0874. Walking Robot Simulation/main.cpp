/**
 * Source: is.gd/UiSihh
 * Date: 2023/11/30
 * Skill:
 * Ref:
 * Runtime: 65 ms, faster than 93.49% of C++ online submissions
 * Memory Usage: 33.90 MB, less than 84.02% of C++ online submissions
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
#define MP(X, Y) make_pair(X, Y)
#define x first
#define y second
typedef pair<int, int> PII;


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<PII> obs;
        for (auto &i: obstacles) obs.insert({i[0], i[1]});
        int res = 0;
        PII cur_pos = MP(0, 0), cur_dir = MP(0, 1);
        for (auto &c: commands) {
            if (c == -2) {
                cur_dir = MP(-cur_dir.y, cur_dir.x);
            } else if (c == -1) {
                cur_dir = MP(cur_dir.y, -cur_dir.x);
            } else {
                for (int k = 1; k <= c; k++) {
                    PII next_pos = MP(cur_pos.x + cur_dir.x, cur_pos.y + cur_dir.y);
                    if (obs.find(next_pos) != end(obs)) break;
                    cur_pos = next_pos;
                    res = max(res, next_pos.x * next_pos.x + next_pos.y * next_pos.y);
                }
            }
        }
        return res;
    }
};