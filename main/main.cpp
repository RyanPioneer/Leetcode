/**
 * Source: is.gd/fL4PzO
 * Date: 2023/11/28
 * Skill:
 * Ref:
 * Runtime: 1367 ms, faster than 9.27% of C++ online submissions
 * Memory Usage: 170.41 MB, less than 15.20% of C++ online submissions
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
#define ll long long
#define MK(X, Y) make_pair(X, Y)
#define x first
#define y second
typedef pair<int, int> PII;
typedef pair<char, char> PCC;
ll mod = 1e9+7;
const int MX = 1024;


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
                if (speed > 0) {
                    if (pos < 2 * MX && visited.find({pos + speed, speed * 2}) == end(visited)) {
                        visited.insert({pos + speed, speed * 2});
                        q.push({pos + speed, speed * 2});
                    }
                    if (visited.find({pos, -1}) == end(visited)) {
                        visited.insert({pos, -1});
                        q.push({pos, -1});
                    }
                } else {
                    if (pos > -MX && visited.find({pos + speed, speed * 2}) == end(visited)) {
                        visited.insert({pos + speed, speed * 2});
                        q.push({pos + speed, speed * 2});
                    }
                    if (visited.find({pos, 1}) == end(visited)) {
                        visited.insert({pos, 1});
                        q.push({pos, 1});
                    }
                }
            }
        }
        return -1;
    }
};