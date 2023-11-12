/**
 * Source: t.ly/WNyEM
 * Date: 2023/11/11
 * Skill:
 * Runtime: 208 ms, faster than 72.27% of C++ online submissions
 * Memory Usage: 112.12 MB, less than 21.57% of C++ online submissions
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

#define ll long long

typedef pair<int, int> pairs;

const int MX = 101;


class Graph {
    int visited[MX] = {0};
    vector<pairs> next[MX];
public:
    Graph(int n, vector<vector<int>>& edges) {
        for (auto &e: edges) {
            next[e[0]].push_back({e[1], e[2]});
        }
    }

    void addEdge(vector<int> edge) {
        next[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        memset(visited, 0, sizeof(visited));
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        pq.push({0, node1});
        while (!pq.empty()) {
            auto [dis, pos] = pq.top();
            pq.pop();
            if (pos == node2) return dis;
            if (visited[pos] == 1) continue;
            visited[pos] = 1;
            for (auto &i: next[pos]) {
                if (visited[i.first] == 1) continue;
                pq.push({i.second + dis, i.first});
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */


int main() {

}