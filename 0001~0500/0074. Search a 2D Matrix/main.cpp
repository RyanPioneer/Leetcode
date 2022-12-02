/** 
 * Source: https://leetcode.com/problems/search-a-2d-matrix/
 * Date: 2022/7/14
 * Skill: Binary Search
 * Runtime: 
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *     
 */

#include<iostream>
#include<vector>
#include<string>
#include<cmath>   
//#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid = matrix.size()*matrix[0].size()/2, start = 0, end = matrix.size()*matrix[0].size()-1, 
        col = matrix[0].size(), row = matrix.size();
        while (start <= mid && mid <= end) {
            if (matrix[mid/col][mid%col] == target)
                return true;
            else if (matrix[mid/col][mid%col] > target) {
                end = mid-1;
                mid = (mid+start)/2;
            } else {
                start = mid+1;
                mid = (mid+end+1)/2;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();