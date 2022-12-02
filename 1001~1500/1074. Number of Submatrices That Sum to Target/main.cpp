/** 
 * Source: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
 * Date: 2022/7/18
 * Skill: 
 * Runtime: 
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= matrix.length <= 100
 *      1 <= matrix[0].length <= 100
 *      -1000 <= matrix[i] <= 1000
 *      -10^8 <= target <= 10^8
 */

#include <iostream>
#include <vector> 
#include <utility>
#include <unordered_map>
//#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        vector<vector<int>> prefix(matrix.size());
        unordered_map<int,int> mp;
        prefix[0].resize(matrix[0].size());
        prefix[0][0] = matrix[0][0];
        for (int i = 1; i < matrix.size(); i++) {
            prefix[i].resize(matrix[0].size());
            prefix[i][0] = matrix[i][0] + prefix[i-1][0];
        }
            
        for (int i = 1; i < matrix[0].size(); i++)
            prefix[0][i] = matrix[0][i] + prefix[0][i-1];
        
        for (int i = 1; i < matrix.size(); i++) 
            for (int j = 1; j < matrix[0].size(); j++) 
                prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + matrix[i][j];
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (prefix[i][j] == target)
                    ans++;
                if (mp.find(prefix[i][j]-target) != mp.end())
                    ans += mp[prefix[i][j]-target];
                mp[prefix[i][j]]++;
            }
        }
        return ans;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();