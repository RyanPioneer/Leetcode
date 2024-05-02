/**
 * Source: t.ly/ch5Em
 * Date: 2024/5/1
 * Skill:
 * Ref:
 * Runtime: 76 ms, faster than 43.82% of C++ online submissions
 * Memory Usage: 42.43 MB, less than 79.78% of C++ online submissions
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
typedef array<int, 3> AI3;


const int MX = 1e2+2;


class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        int dir[5] = {0, 1, 0, -1, 0};
        int dis[MX][MX];
        char prev[MX][MX];

        fill(dis[0], dis[MX - 1] + MX, INT32_MAX);

        int next[MX][MX][4] = {0};
        for (int i )

        priority_queue<AI3, vector<AI3>, greater<>> pq;
        pq.push({0, ball[0] * n + ball[1], 0});
        while (!pq.empty()) {
            auto [d, pos, p] = pq.top();
            pq.pop();
            if (d >= dis[pos / n][pos % n]) continue;
            dis[pos / n][pos % n] = d;
            for (int i = 0; i < 4; i++) {

            }
        }
    }
};