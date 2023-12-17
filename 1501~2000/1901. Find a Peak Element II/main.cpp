/**
 * Source: jpeg.ly/lwQ6k
 * Date: 2023/12/16
 * Skill:
 * Ref:
 * Runtime: 122 ms, faster than 91.15% of C++ online submissions
 * Memory Usage: 46.92 MB, less than 19.69% of C++ online submissions
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
const int MX = 501;


class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = SZ(mat), n = SZ(mat[0]), mx[MX];
        for (int i = 0; i < m; i++) {
            int num = 0;
            for (auto &j: mat[i]) {
                num = max(num, j);
            }
            mx[i] = num;
        }
        int left = 0, right = m - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mx[mid] < mx[mid + 1]) left = mid + 1;
            else right = mid;
        }
        for(int i = 0; i < n; i++) {
            if (mat[left][i] == mx[left]) {
                return {left, i};
            }
        }
        return {-1, -1};
    }
};