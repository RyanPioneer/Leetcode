/**
 * Source: t.ly/uX3o3
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 25 ms, faster than 28.36% of C++ online submissions
 * Memory Usage: 16.58 MB, less than 29.85% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


class NumMatrix {
public:
    int m, n;
    vector<vector<int>> prefixSum;
    vector<vector<int>> prevModify;
    vector<vector<int>> matrix, matrix2;

    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        this->matrix2 = matrix;
        m = matrix.size(), n = matrix[0].size();
        prefixSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    void update(int row, int col, int val) {
        prevModify.push_back({row, col, val});
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = prefixSum[row2 + 1][col2 + 1] - prefixSum[row2 + 1][col1] - prefixSum[row1][col2 + 1] + prefixSum[row1][col1];
        for (auto &v: prevModify) {
            if (v[0] <= row2 && v[1] <= col2 && v[0] >= row1 && v[1] >= col1) {
                res += v[2] - matrix2[v[0]][v[1]];
                matrix2[v[0]][v[1]] = v[2];
            }
        }
        matrix2 = matrix;
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */