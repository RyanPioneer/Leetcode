/**
 * Source: ibit.ly/4t8C3
 * Date: 2023/10/3
 * Skill:
 * Runtime: 31 ms, faster than 86.39% of C++ online submissions
 * Memory Usage: 16.84 MB, less than 10.33% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m, n <= 150
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
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0, m = mat.size(), n = mat[0].size();
        vector<int> histogram(n + 1, 0);
        for (int bottom = 0; bottom < m; ++bottom) {
            for (int i = 0; i < n; i++)
                histogram[i + 1] = mat[bottom][i] == 1 ? histogram[i + 1] + 1 : 0;
            stack<int> s;
            s.push(0);
            int prev = 0;
            for (int i = 0; i < n; i++) {
                while (histogram[i + 1] < histogram[s.top()]) {
                    int j = s.top();
                    s.pop();
                    prev -= histogram[j] * (j - s.top());
                }
                prev += histogram[i + 1] * (i + 1 - s.top());
                res += prev;
                s.push(i + 1);
            }
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}