/**
 * Source: tinyurl.com/2bc663ts
 * Date: 2025/4/5
 * Skill:
 * Ref:
 * Runtime: 124 ms, faster than 22.82% of C++ online submissions
 * Memory Usage: 584.00 MB, less than 6.23% of C++ online submissions
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

class SnakeGame {
public:
    int width, height;
    vector<vector<int>> food, board;
    int foodIndex = 0;
    int score = 0;
    int x = 0, y = 0;
    queue<pair<int, int>> snake;

public:
    SnakeGame(int width, int height, vector<vector<int>>& food)
    {
        this->width = width;
        this->height = height;
        this->board = vector<vector<int>>(height, vector<int>(width, 0));
        board[0][0] = 1;
        this->food = food;
        this->snake.push({ 0, 0 });
    }

    bool checkFeasible(int x, int y)
    {
        return x >= 0 && x < height && y >= 0 && y < width;
    }

    int move(string direction)
    {
        if (direction == "U") {
            x--;
        } else if (direction == "D") {
            x++;
        } else if (direction == "L") {
            y--;
        } else if (direction == "R") {
            y++;
        }

        if (!checkFeasible(x, y) || (board[x][y] == 1 && !(x == snake.front().first && y == snake.front().second))) {
            return -1;
        }

        if (foodIndex < food.size() && food[foodIndex][0] == x && food[foodIndex][1] == y) {
            score++;
            foodIndex++;
        } else {
            auto [tailX, tailY] = snake.front();
            snake.pop();
            board[tailX][tailY] = 0;
        }

        board[x][y] = 1;
        snake.push({ x, y });
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
