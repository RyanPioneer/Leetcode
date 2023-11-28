/**
 * Source: is.gd/fL4PzO
 * Date: 2023/11/28
 * Skill:
 * Ref:
 * Runtime: 457 ms, faster than 29.93% of C++ online submissions
 * Memory Usage: 64.92 MB, less than 35.16% of C++ online submissions
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
typedef pair<int, int> PII;
const int MX = 1e4 + 1;


class Solution {
public:
    int racecar(int target) {
        set<PII> visited;
        visited.insert({0, 1});
        queue<PII> q;
        q.push({0, 1});
        int step = -1;
        while (!q.empty()) {
            int sz = SZ(q);
            step++;
            while (sz--) {
                auto [pos, speed] = q.front();
                q.pop();
                if (pos == target) return step;
                int r_speed = speed > 0 ? -1 : 1;
                if (visited.find({pos, r_speed}) == end(visited)) {
                    visited.insert({pos, r_speed});
                    q.push({pos, r_speed});
                }
                if (abs(pos + speed - target) < target && visited.find({pos + speed, speed * 2}) == end(visited)) {
                    visited.insert({pos + speed, speed * 2});
                    q.push({pos + speed, speed * 2});
                }
            }
        }
        return -1;
    }
};