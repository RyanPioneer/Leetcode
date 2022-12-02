/** 
 * Source: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
 * Date: 2021/7/11
 * Skill: 
 * Runtime: 
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      
 */

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<vector<int>,int>>myQue;
        vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int row = maze.size(), col = maze[0].size();
        myQue.push(make_pair(entrance, 0));
        maze[entrance[0]][entrance[1]] = '+';
        while(!myQue.empty()) {
            vector<int>curPos = myQue.front().first;
            int dis = myQue.front().second;
            myQue.pop();
            for(auto i:dir) {
                vector<int>vec = {curPos[0]+i[0], curPos[1]+i[1]};
                if(vec[0]>=0 && vec[0]<row && vec[1]>=0 && vec[1]<col && maze[vec[0]][vec[1]] == '.') {
                    if(vec[0] == 0 || vec[1] == 0 || vec[0] == row-1 || vec[1] == col-1)
                        return dis+1;
                    myQue.push(make_pair(vec, dis+1));
                    maze[vec[0]][vec[1]] = '+';
                }
            }
        }
        return -1;
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
