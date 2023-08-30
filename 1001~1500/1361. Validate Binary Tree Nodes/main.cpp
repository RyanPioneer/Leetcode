/**
 * Source: https://rb.gy/miv88
 * Date: 2023/8/30
 * Skill:
 * Runtime: 42 ms, faster than 71.34% of C++ online submissions
 * Memory Usage: 32.44 MB, less than 78.77% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 10 ** 4
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define ll long long
// using ll = long long;


class Solution {
public:
    int find_father(int x, vector<int>& father) {
        if (father[x] != x)
            father[x] = find_father(father[x], father);
        return father[x];
    }
    void union_set(int x, int y, vector<int>& father) {
        int x_father = find_father(x, father), y_father = find_father(y, father);
        if (x_father != y_father)
            father[y_father] = x_father;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> father(n, 0);
        for (int i = 0; i < n; i++) father[i] = i;
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (find_father(leftChild[i], father) != leftChild[i] || find_father(leftChild[i], father) == find_father(i, father))
                    return false;
                union_set(i, leftChild[i], father);
            }
            if (rightChild[i] != -1) {
                if (find_father(rightChild[i], father) != rightChild[i] || find_father(rightChild[i], father) == find_father(i, father))
                    return false;
                union_set(i, rightChild[i], father);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (find_father(i, father) != find_father(i + 1, father))
                return false;
        }
        return true;
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
    vector<int> tasks{1,2,3,1};
}