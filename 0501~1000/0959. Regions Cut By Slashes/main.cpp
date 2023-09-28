/**
 * Source: ibit.ly/gjLuU
 * Date: 2023/9/28
 * Skill:
 * Runtime: 8 ms, faster than 69.87% of C++ online submissions
 * Memory Usage: 9.80 MB, less than 76.49% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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
    vector<int> father;
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size(), res = 1;
        father.resize(pow(n + 1, 2));
        for (int i = 0; i < pow(n + 1, 2); i++)
            father[i] = i;
        for (int i = 0; i < n; i++) {
            union_set(i, i + 1);
            union_set((n + 1) * n + i, (n + 1) * n + i + 1);
            union_set((n + 1) * i, (n + 1) * (i + 1));
            union_set((n + 1) * i + n, (n + 1) * (i + 1) + n);
        }
        for (int i = 0; i < n; i++) {
            for (int idx = 0; idx < n; idx++) {
                if (grid[i][idx] == ' ')
                    continue;
                else if (grid[i][idx] == '/') {
                    int g1 = i * (n + 1) + (idx + 1);
                    int g2 = (i + 1) * (n + 1) + idx;
                    if (find_father(g1) == find_father(g2))
                        res++;
                    union_set(g1, g2);
                } else {
                    int g1 = i * (n + 1) + idx;
                    int g2 = (i + 1) * (n + 1) + (idx + 1);
                    if (find_father(g1) == find_father(g2))
                        res++;
                    union_set(g1, g2);
                }
            }
        }
        return res;
    }
    int find_father(int x) {
        if (father[x] != x)
            father[x] = find_father(father[x]);
        return father[x];
    }
    void union_set(int x, int y) {
        int x_father = find_father(x), y_father = find_father(y);
        if (x_father != y_father)
            father[x_father] = y_father;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {7,6}};
}