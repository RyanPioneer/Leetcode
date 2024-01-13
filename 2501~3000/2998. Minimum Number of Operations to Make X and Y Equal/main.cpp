/**
 * Source: jpeg.ly/sM-P8
 * Date: 2024/1/12
 * Skill:
 * Ref:
 * Runtime: 55 ms, faster than 41.37% of C++ online submissions
 * Memory Usage: 24.42 MB, less than 40.26% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;
ll mod = 1e9+7;
typedef pair<int, int> PII;


class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_set<int> visited;
        int step = 0;
        queue<int> q;
        q.push(x);
        visited.insert(x);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int cur = q.front();
                q.pop();
                if (cur == y) return step;
                if (cur % 11 == 0 && visited.find(cur / 11) == end(visited)) {
                    ll next = cur / 11;
                    q.push(next);
                    visited.insert(next);
                }
                if (cur % 5 == 0 && visited.find(cur / 5) == end(visited)) {
                    ll next = cur / 5;
                    q.push(next);
                    visited.insert(next);
                }
                if (visited.find(cur - 1) == end(visited)) {
                    q.push(cur - 1);
                    visited.insert(cur - 1);
                }
                if (visited.find(cur + 1) == end(visited)) {
                    q.push(cur + 1);
                    visited.insert(cur + 1);
                }
            }
            step++;
        }
        return -1;
    }
};