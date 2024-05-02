/**
 * Source: t.ly/Pk6vt
 * Date: 2024/5/2
 * Skill:
 * Ref:
 * Runtime: 13 ms, faster than 24.64% of C++ online submissions
 * Memory Usage: 11.72 MB, less than 53.44% of C++ online submissions
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
typedef pair<int, int> PII;
#define MK make_pair


// This is the robot's control interface.
// You should not implement it, or speculate about its implementation
  class Robot {
    public:
      // Returns true if the cell in front is open and robot moves into the cell.
      // Returns false if the cell in front is blocked and robot stays in the current cell.
      bool move();

      // Robot will stay in the same cell after calling turnLeft/turnRight.
      // Each turn will be 90 degrees.
      void turnLeft();
      void turnRight();

      // Clean the current cell.
      void clean();
  };


class Solution {
public:
    void cleanRoom(Robot& robot) {
        set<PII> visited;
        PII pos = MK(0, 0), initDir = MK(0, 1);
        int dir[5] = {0, 1, 0, -1, 0};

        function<void(PII &)> rotate = [&](PII &dir1) {
            if (dir1.first == 0 && dir1.second == 1) {
                robot.turnRight();
                dir1 = {1, 0};
            } else if (dir1.first == 1 && dir1.second == 0) {
                robot.turnRight();
                dir1 = {0, -1};
            } else if (dir1.first == 0 && dir1.second == -1) {
                robot.turnRight();
                dir1 = {-1, 0};
            } else {
                robot.turnRight();
                dir1 = {0, 1};
            }
        };

        function<void(PII, PII &)> dfs = [&](PII curPos, PII &curDir) {
            robot.clean();
            visited.insert(curPos);
            for (int i = 0; i < 4; i++) {
                PII nextPos = {curPos.first + dir[i], curPos.second + dir[i + 1]};
                if (visited.find(nextPos) == end(visited)) {
                    visited.insert(nextPos);
                    PII nextDir = {dir[i], dir[i + 1]};
                    while (curDir != nextDir) {
                        rotate(curDir);
                    }
                    if (robot.move()) {
                        dfs(nextPos, curDir);
                        if (nextDir.first != 0) nextDir.first *= -1;
                        if (nextDir.second != 0) nextDir.second *= -1;
                        while (curDir != nextDir) {
                            rotate(curDir);
                        }
                        robot.move();
                    }
                }
            }
        };

        dfs(pos, initDir);
    }
};