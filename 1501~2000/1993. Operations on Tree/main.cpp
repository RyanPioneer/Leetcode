/**
 * Source: tinyurl.com/ysrk3e23
 * Date: 2023/10/27
 * Skill:
 * Runtime: 329 ms, faster than 80.58% of C++ online submissions
 * Memory Usage: 170.55 MB, less than 32.04% of C++ online submissions
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
#include <functional>
#include <list>

using namespace std;

const int MX = 2001;

class LockingTree {
    int sz;
    vector<int> children[MX], parent;
    bool locked[MX] = {false};
    int users[MX];
public:
    LockingTree(vector<int>& parent) {
        sz = parent.size();
        this->parent = parent;
        for (int i = 1; i < sz; i++) {
            children[parent[i]].push_back(i);
            locked[i] = false;
        }
    }

    bool lock(int num, int user) {
        if (!locked[num]) {
            locked[num] = true;
            users[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (locked[num] && users[num] == user) {
            locked[num] = false;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (locked[num]) return false;
        bool flag = true;
        int par = parent[num];
        while (par !=-1) {
            if (locked[par]) {
                flag = false;
                break;
            }
            par = parent[par];
        }
        if (!flag)
            return false;
        queue<int> q;
        for (auto i: children[num]) q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (locked[cur]) {
                flag = false;
                locked[cur] = false;
            }
            for (auto i: children[cur]) {
                q.push(i);
            }
        }
        if (!flag) {
            locked[num] = true;
            users[num] = user;
        }
        return !flag;
    }
};


int main() {
//    Solution s;
}