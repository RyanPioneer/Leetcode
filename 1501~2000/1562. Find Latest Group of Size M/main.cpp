/**
 * Source: t.ly/8M_39
 * Date: 2023/9/25
 * Skill:
 * Runtime: 117 ms, faster than 77.07% of C++ online submissions
 * Memory Usage: 78.23 MB, less than 90.45% of C++ online submissions
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
    int father[100001];
    int group2size[100001];
public:
    int findLatestStep(vector<int>& arr, int m) {
        int num = 0, res = -1, sz = arr.size();
        string s(sz, '0');
        for (int i = 0; i <= sz; i++) {
            father[i] = i;
            group2size[i] = 0;
        }
        for (int i = 0; i < sz; i++) {
            int pos = arr[i] - 1;
            s[pos] = '1';
            group2size[find_father(pos)] = 1;
            if (pos > 0 && s[pos - 1] == '1') {
                if (group2size[find_father(pos - 1)] == m)
                    num--;
                union_set(pos, pos - 1);
            }
            if (pos + 1 < sz && s[pos + 1] == '1') {
                if (group2size[find_father(pos + 1)] == m)
                    num--;
                union_set(pos, pos + 1);
            }
            if (group2size[find_father(pos)] == m)
                num++;
            if (num > 0)
                res = i + 1;
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
        if (x_father != y_father) {
            group2size[x_father] += group2size[y_father];
            group2size[y_father] = 0;
            father[y_father] = x_father;
        }
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {2, 10},
                             {1, 10},
                             {2, 3},
                             {6,10},
                             {4,3},
                             {8,6},
                             {5,8},
                             {7,6}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}