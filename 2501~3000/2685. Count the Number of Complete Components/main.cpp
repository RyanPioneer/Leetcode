/**
 * Source: https://rb.gy/tkyc4
 * Date: 2023/8/31
 * Skill:
 * Runtime: 259 ms, faster than 30.90% of C++ online submissions
 * Memory Usage: 153.7 MB, less than 6.55% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 50
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <numeric>

using namespace std;

#define ll long long
// using ll = long long;

typedef pair<int, int> pairs;

class Solution {
public:
    int find_father(int x, vector<int> & father) {
        if (father[x] != x)
            father[x] = find_father(father[x], father);
        return father[x];
    }
    void union_set(int x, int y, vector<int> & father) {
        int x_father = find_father(x, father), y_father = find_father(y, father);
        if (x_father != y_father)
            father[x_father] = y_father;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> father(n, 0);
        vector<set<int>> adj_set(n);
        for (int i = 0; i < n; i++)
            father[i] = i;
        for (auto edge : edges) {
            union_set(edge[0], edge[1], father);
            adj_set[edge[0]].insert(edge[1]);
            adj_set[edge[1]].insert(edge[0]);
        }
        int res = 0;
        set<int> groups;
        map<int, set<int>> id2group;
        for (int i = 0; i < n; i++) {
            if (id2group.find(find_father(i, father)) == id2group.end()) {
                set<int> myset;
                myset.insert(i);
                id2group[find_father(i, father)] = myset;
            } else
                id2group[find_father(i, father)].insert(i);
        }
        for (int i = 0; i < n; i++) {
            int id = find_father(i, father), group_size = id2group[find_father(i, father)].size();
            if (groups.find(id) == groups.end()) {
                groups.insert(id);
                int flag = true;
                for (auto j: id2group[id]) {
                    if (adj_set[j].size() != group_size - 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    res++;
            }
        }
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
    vector<int> arr{3,2,2,4,3};
    int target = 3;

    cout << target << endl;
}