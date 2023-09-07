/**
 * Source: https://rb.gy/n668r
 * Date: 2023/9/7
 * Skill:
 * Runtime: 152 ms, faster than 66.67% of C++ online submissions
 * Memory Usage: 60.46 MB, less than 42.95% of C++ online submissions
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
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> father(s.length());
        for (int i = 0; i < father.size(); i++)
            father[i] = i;
        for (auto p: pairs)
            union_set(p[0], p[1], father);
        unordered_map<int, multiset<char>> group2char;
        for (int i = 0; i < s.length(); i++)
            group2char[find_father(i, father)].insert(s[i]);
        string res;
        for (int i = 0; i < s.length(); i++) {
            char c = *group2char[find_father(i, father)].begin();
            res += c;
            group2char[find_father(i, father)].erase(group2char[find_father(i, father)].lower_bound(c));
        }
        return res;
    }
    int find_father(int x, vector<int> &father) {
        if (father[x] != x)
            father[x] = find_father(father[x], father);
        return father[x];
    }
    void union_set(int x, int y, vector<int> &father) {
        int x_father = find_father(x, father), y_father = find_father(y, father);
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
    string ss = "DID";

}