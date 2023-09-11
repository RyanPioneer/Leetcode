/**
 * Source: https://rb.gy/emifw
 * Date: 2023/9/11
 * Skill:
 * Runtime: 380 ms, faster than 81.55% of C++ online submissions
 * Memory Usage: 99.20 MB, less than 80.36% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m, n <= 1000
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(matrix[0][0]);
        for (int i = 1; i < m; ++i) {
            matrix[i][0] ^= matrix[i - 1][0];
            if (pq.size() < k)
                pq.push(matrix[i][0]);
            else if (pq.top() < matrix[i][0]) {
                pq.pop();
                pq.push(matrix[i][0]);
            }
        }
        for (int i = 1; i < n; ++i) {
            matrix[0][i] ^= matrix[0][i - 1];
            if (pq.size() < k)
                pq.push(matrix[0][i]);
            else if (pq.top() < matrix[0][i]) {
                pq.pop();
                pq.push(matrix[0][i]);
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
                if (pq.size() < k)
                    pq.push(matrix[i][j]);
                else if (pq.top() < matrix[i][j]) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
}