/**
 * Source: jpeg.ly/sM-P8
 * Date: 2024/1/12
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 87.62% of C++ online submissions
 * Memory Usage: 8.52 MB, less than 82.90% of C++ online submissions
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
    int upper_bound;
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x < y) return y - x;
        upper_bound = x + x - y;
        vector<int> dis(upper_bound + 1, -1);
        dis[x] = 0;
        queue<int> q;
        q.push(x);
        while (!q.empty() && dis[y] == -1) {
            int cur = q.front();
            q.pop();
            if (cur % 11 == 0 && dis[cur / 11] == -1 && cur > y) {
                dis[cur / 11] = dis[cur] + 1;
                q.push(cur / 11);
            }
            if (cur % 5 == 0 && dis[cur / 5] == -1 && cur > y) {
                dis[cur / 5] = dis[cur] + 1;
                q.push(cur / 5);
            }
            if (cur + 1 <= upper_bound && dis[cur + 1] == -1) {
                dis[cur + 1] = dis[cur] + 1;
                q.push(cur + 1);
            }
            if (cur - 1 > 0 && dis[cur - 1] == -1 && cur > y) {
                dis[cur - 1] = dis[cur] + 1;
                q.push(cur - 1);
            }
        }
        return dis[y];
    }
};
