/**
 * Source: ibit.ly/bufej
 * Date: 2023/11/9
 * Skill:
 * Runtime: 83 ms, faster than 90.29% of C++ online submissions
 * Memory Usage: 41.08 MB, less than 59.77% of C++ online submissions
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

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int visited[MX] = {0}, res = 0;
        vector<pairs> edges[MX];
        for (auto &e: times) {
            edges[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            while (!pq.empty() && (pq.top().second != k && visited[pq.top().second] != 0)) {
                pq.pop();
            }
            if (pq.empty()) break;
            auto [time, cur] = pq.top();
            pq.pop();
            visited[cur] = time;
            for (auto &i: edges[cur]) {
                if (visited[i.first] > 0 || i.first == k) continue;
                pq.push({time + i.second, i.first});
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i != k && visited[i] == 0) {
                return -1;
            } else {
                res = max(res, visited[i]);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}