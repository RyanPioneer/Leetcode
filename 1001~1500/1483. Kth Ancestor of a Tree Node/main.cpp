/**
 * Source: https://rb.gy/lltne
 * Date: 2023/8/28
 * Skill: binary lifting
 * Runtime: 294 ms, faster than 65.58% of C++ online submissions
 * Memory Usage: 134.92 MB, less than 28.77% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

class TreeAncestor {
    vector<vector<int>> p;
public:
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> p(n, vector<int>(20, -1));
        for (int i = 0; i < n; i++)
            p[i][0] = parent[i];
        for (int i = 1; i < 20; i++) {
            for (int j = 0; j < n; j++) {
                if (p[j][i - 1] != -1)
                    p[j][i] = p[p[j][i - 1]][i - 1];
            }
        }
        this->p = p;
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if ((k >> i) & 1)
                node = p[node][i];
            if (node == -1)
                break;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

//static const auto io_sync_off = []() {
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();

int main() {
//    TreeAncestor s;
    vector<int> v{1,2,3};
    for (auto i: v)
        cout << i << endl;
}