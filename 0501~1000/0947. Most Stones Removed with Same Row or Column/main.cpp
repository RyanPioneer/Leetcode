/** 
 * Source: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 * Date: 2022/11/14
 * Skill: DFS
 * Runtime: 512 ms, faster than 28.66%
 * Memory Usage: 14.1 MB, less than 95.74%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= stones.length <= 1000
 *      0 <= xi, yi <= 10^4
 *  * No two stones are at the same coordinate point
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int num = stones.size(), sol = 0;
        vector<bool> visited(num, 0);
        for (int i = 0; i < num; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                sol += dfs(stones, i, visited, num);
            }
        }
        return sol;
    }

    int dfs(vector<vector<int>>& stones, int index, vector<bool>& visited, int num) {
        int sol = 0;
        for (int i = 0; i < num; i++) {
            if (!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])) {
                visited[i] = 1;
                sol += dfs(stones, i, visited, num)+1;
            }
        }
        return sol;
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