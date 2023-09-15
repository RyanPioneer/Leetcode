/**
 * Source: https://rb.gy/cnu6u
 * Date: 2023/9/15
 * Skill: Prim
 * Runtime: 122 ms, faster than 87.70% of C++ online submissions
 * Memory Usage: 43.20 MB, less than 76.21% of C++ online submissions
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

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
    vector<int> father;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        int sz = points.size(), res = 0;
        unordered_set<int> cand;
        father.resize(sz);
        for (int i = 0; i < sz; i++)
            father[i] = i;
        for (int i = 1; i < sz; i++) {
            cand.insert(i);
            int dis = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
            pq.push(make_pair(dis, i));
        }
        while (!pq.empty() && !cand.empty()) {
            auto [dis, pos] = pq.top();
            pq.pop();
            if (find_father(0) == find_father(pos))
                continue;
            cand.erase(pos);
            res += dis;
            union_set(0, pos);
            for (auto i: cand) {
                int dis = abs(points[pos][0] - points[i][0]) + abs(points[pos][1] - points[i][1]);
                pq.push(make_pair(dis, i));
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


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
}