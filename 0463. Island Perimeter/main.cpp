// Source: https://leetcode.com/problems/island-perimeter/
// Date: 2021/7/9

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int peri = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == 1) {
                    if((i>0 && grid[i-1][j] == 0) || i==0)
                        peri++;
                    if((i<row-1 && grid[i+1][j] == 0) || i == row-1)
                        peri++;
                    if((j>0 && grid[i][j-1] == 0) || j == 0)
                        peri++;
                    if((j<col-1 && grid[i][j+1] == 0) || j == col-1)
                        peri++;
                }
            }
        }
        return peri;
    }
};