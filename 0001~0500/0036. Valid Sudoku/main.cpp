/**
 * Source: https://leetcode.com/problems/valid-sudoku/
 * Date: 2022/7/12
 * Skill:
 * Runtime:
 * Memory Usage:
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> row(9,0), col(9,0), sub(9,0);
            int sub_row = 3*(i/3), sub_col = 3*(i%3);
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    if (row[board[i][j]-'1'])
                        return false;
                    else
                        row[board[i][j]-'1'] = 1;
                }
                if (isdigit(board[j][i])) {
                    if (col[board[j][i]-'1'])
                        return false;
                    else
                        col[board[j][i]-'1'] = 1;
                }
                if (isdigit(board[sub_row+j/3][sub_col+j%3])) {
                    if (sub[board[sub_row+j/3][sub_col+j%3]-'1'])
                        return false;
                    else
                        sub[board[sub_row+j/3][sub_col+j%3]-'1'] = 1;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board =
    {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'},
    };
    cout << s.isValidSudoku(board);
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
