/**
 * Source: https://rb.gy/emifw
 * Date: 2023/9/11
 * Skill:
 * Runtime: 527 ms, faster than 53.87% of C++ online submissions
 * Memory Usage: 90.10 MB, less than 100.00% of C++ online submissions
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
        for (int i = 1; i < m; ++i)
            matrix[i][0] ^= matrix[i - 1][0];
        for (int i = 1; i < n; ++i)
            matrix[0][i] ^= matrix[0][i - 1];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];

        int left = 0, right = 1e6;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (count(mid, matrix) < k)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
    int count(int num, vector<vector<int>>& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                if (matrix[i][j] >= num)
                    res++;
        return res;
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