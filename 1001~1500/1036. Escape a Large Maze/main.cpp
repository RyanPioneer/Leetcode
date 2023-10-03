/**
 * Source: ibit.ly/4xkVH
 * Date: 2023/10/3
 * Skill:
 * Runtime: 251 ms, faster than 52.97% of C++ online submissions
 * Memory Usage: 62.67 MB, less than 51.49% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      0 <= blocked.length <= 200
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
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        return check_feasible(blocked, source, target) && check_feasible(blocked, target, source);
    }
    bool check_feasible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<ll> visited, blocked_pos;
        for (auto i: blocked)
            blocked_pos.insert(i[0] + i[1] * 1e6);
        int dir[5] = {0, 1, 0, -1, 0}, num = 1;
        queue<pairs> q;
        visited.insert(source[0] + source[1] * 1e6);
        q.push({source[0], source[1]});
        while (!q.empty() && num <= 20000) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dir[i], yy = y + dir[i + 1];
                ll l = (ll) yy * 1e6 + xx;
                if (xx == target[0] && yy == target[1])
                    return true;
                if (check(xx, yy) && blocked_pos.find(l) == blocked_pos.end() &&
                    visited.find(l) == visited.end()) {
                    num++;
                    visited.insert(l);
                    q.push({xx, yy});
                }
            }
        }
        return num > 20000;
    }
    bool check(int x, int y) {
        return 0 <= x && x < 1e6 && 0 <= y && y < 1e6;
    }
};



int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}