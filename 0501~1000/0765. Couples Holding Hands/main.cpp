/**
 * Source: https://rb.gy/47b67
 * Date: 2023/9/7
 * Skill:
 * Runtime: 0 ms, faster than 100% of C++ online submissions
 * Memory Usage: 7.4 MB, less than 37.87% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
    vector<int> father;
public:
    int minSwapsCouples(vector<int>& row) {
        father.resize(row.size());
        for (int i = 0; i < row.size() / 2; i++) {
            father[2 * i] = 2 * i;
            father[2 * i + 1] = 2 * i;
        }
        for (int i = 0; i < row.size(); i += 2)
            union_set(row[i], row[i + 1]);
        int res = 0;
        unordered_map<int, int> group2count;
        for (int i = 0; i < row.size(); i++)
            group2count[find_father(i)]++;
        for (auto i: group2count)
            res += i.second / 2 - 1;
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


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> row{0,2,1,3};
    int res = s.minSwapsCouples(row);
    cout << res << endl;
}