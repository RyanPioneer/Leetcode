/**
 * Source: is.gd/JTQ2Ag
 * Date: 2023/11/26
 * Skill:
 * Ref:
 * Runtime: 11 ms, faster than 83.33% of C++ online submissions
 * Memory Usage: 27.46 MB, less than 25.00% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = SZ(mat), n = SZ(mat[0]);
        k %= n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};