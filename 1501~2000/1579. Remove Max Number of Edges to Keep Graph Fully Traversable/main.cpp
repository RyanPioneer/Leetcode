/**
 * Source: https://rb.gy/ngv9h
 * Date: 2023/8/29
 * Skill:
 * Runtime: 531 ms, faster than 67.83% of C++ online submissions
 * Memory Usage: 216.96 MB, less than 5.29% of C++ online submissions
 * Time complexity: O(n log(n))
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#define ll long long

using namespace std;


class Solution {
public:
    int find_father(int x, vector<int>& father) {
        if (father[x] != x)
            father[x] = find_father(father[x], father);
        return father[x];
    }
    void union_father(int x, int y, vector<int>& father) {
        int x_father = find_father(x, father), y_father = find_father(y, father);
        if (x_father != y_father)
            father[x_father] = y_father;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edge1, edge2, edge3;
        int count1 = 0, count2 = 0, count3 = 0, total = 0;
        vector<int> father(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            father[i] = i;
        }
        for (auto i: edges) {
            total++;
            vector<int> v{i[1], i[2]};
            if (i[0] == 1)
                edge1.push_back(v);
            else if (i[0] == 2)
                edge2.push_back(v);
            else
                edge3.push_back(v);
        }
        for (int i = 0; i < edge3.size(); ++i) {
            if (find_father(edge3[i][0], father) != find_father(edge3[i][1], father)) {
                count1++;
                union_father(find_father(edge3[i][0], father), find_father(edge3[i][1], father), father);
            }
        }
        if (count1 == n - 1)
            return total - count1;

        vector<int> father0 = father;
        for (int i = 0; i < edge2.size(); ++i) {
            if (find_father(edge2[i][0], father) != find_father(edge2[i][1], father)) {
                count2++;
                union_father(find_father(edge2[i][0], father), find_father(edge2[i][1], father), father);
            }
        }
        if (count1 + count2 != n - 1)
            return -1;
        for (int i = 0; i < edge1.size(); ++i) {
            if (find_father(edge1[i][0], father0) != find_father(edge1[i][1], father0)) {
                count3++;
                union_father(find_father(edge1[i][0], father0), find_father(edge1[i][1], father0), father0);
            }
        }
        if (count1 + count3 != n - 1)
            return -1;
        return total - count1 - count2 - count3;
    }
};

//static const auto io_sync_off = []() {
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();

int main() {
    Solution s;
    vector<vector<int>> edges {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    int n = 4;
    int res = s.maxNumEdgesToRemove(n, edges);
    cout << res << endl;
}