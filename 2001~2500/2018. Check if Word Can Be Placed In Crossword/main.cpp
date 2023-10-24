/**
 * Source: tinyurl.com/yqdwsv5q
 * Date: 2023/10/24
 * Skill:
 * Runtime: 153 ms, faster than 87.50% of C++ online submissions
 * Memory Usage: 59.94 MB, less than 77.50% of C++ online submissions
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
#include <bitset>
#include <functional>
#include <list>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), sz = word.length();
        int dir[5] = {0, 1, 0, -1, 0};
        function<bool(int, int)> check_boundary;
        check_boundary = [=](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        function<bool(int, int, int, int)> check;
        check = [&](int x, int y, int dirx, int diry) {
            for (int i = 1; i < sz; i++) {
                x += dirx;
                y += diry;
                if (!check_boundary(x, y))
                    return false;
                if (board[x][y] == word[i] || board[x][y] == ' ')
                    continue;
                else
                    return false;
            }
            return true;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] || board[i][j] == ' ') {
                    for (int k = 0; k < 4; k++) {
                        int dirx = dir[k], diry = dir[k + 1];
                        if ((!check_boundary(i - dirx, j - diry) || board[i - dirx][j - diry] == '#')
                            && (!check_boundary(i + sz * dirx, j + sz * diry) || board[i + sz * dirx][j + sz * diry] == '#')) {
                            if (check(i, j, dirx, diry))
                                return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}