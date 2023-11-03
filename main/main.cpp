/**
 * Source: t.ly/Fa-Rs
 * Date: 2023/11/3
 * Skill:
 * Runtime: 189 ms, faster than 67.20% of C++ online submissions
 * Memory Usage: 65.81 MB, less than 17.36% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 200
 */

#include "utilities.h"
#include "utilities.cpp"

const int MX = 201;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        priority_queue<pairs> pq;
        unordered_set<int> cand;
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                num += 1 - grid[i][j];
            }
            pq.push({num, i});
        }
        for (int i = 0; i < n - 1; i++) {
            int num = n - 1 - i;
            while (!pq.empty() && pq.top().first >= num) {
                cand.insert(pq.top().second);
                pq.pop();
            }
            if (cand.empty()) return -1;
            int dis = n, chosen;
            for (auto j: cand) {
                int diff = abs(j - i);
                if (diff < dis) {
                    dis = diff;
                    chosen = j;
                } else if (diff == dis) {
                    chosen = min(chosen, j);
                }
            }
            res += dis;
            cand.erase(chosen);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}