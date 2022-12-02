/**
 * Source: https://leetcode.com/problems/rotate-image/
 * Date: 2022/7/12
 * Skill:
 * Runtime:
 * Memory Usage:
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      You have to rotate the image in-place,
 *      which means you have to modify the input 2D matrix directly.
 *      DO NOT allocate another 2D matrix and do the rotation.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int sz = matrix.size();
        for (int i = 0; i < sz/2; i++) {
            for (int j = 0; j < sz-i*2-1; j++) {
                int tmp = matrix[sz-1-i-j][i];
                matrix[sz-1-i-j][i] = matrix[sz-1-i][sz-1-i-j];
                matrix[sz-1-i][sz-1-i-j] = matrix[i+j][sz-1-i];
                matrix[i+j][sz-1-i] = matrix[i][i+j];
                matrix[i][i+j] = tmp;
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> vec = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    s.rotate(vec);
    for (auto i : vec) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

/*static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();*/