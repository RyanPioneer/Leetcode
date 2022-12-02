/** 
 * Source: https://leetcode.com/problems/word-search/
 * Date: 2022/11/24
 * Skill: Back Tracking
 * Runtime: 529 ms, faster than 63.60%
 * Memory Usage: 8.1 MB, less than 17.64%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      
 */

#include <iostream>
#include <vector>
#include <utility>
#include <string> 
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int len) {
        if (word.length() <= len)
            return true;
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[len])
            return false;
        char cur = board[i][j];
        board[i][j] = '.';
        for (int k = 0; k < 4; k++) {
            if (dfs(board,word,i+dir[k][0],j+dir[k][1],len+1)) {
                board[i][j] = cur;
                return true;
            }
        }
        board[i][j] = cur;
        return false;
    }
};

int main() {
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();