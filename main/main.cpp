/**
 * Source: is.gd/fL4PzO
 * Date: 2023/11/26
 * Skill:
 * Ref:
 * Runtime: 19 ms, faster than 91.39% of C++ online submissions
 * Memory Usage: 10.54 MB, less than 82.78% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= target <= 10 ** 4
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
#define SZ(X) ((int)(X).size())
#define ll long long
#define MK(X, Y) make_pair(X, Y)
typedef pair<int, int> PII;
typedef pair<char, char> PCC;
ll mod = 1e9+7;
const int MX = 1e4 + 1;


class Solution {
public:
    int racecar(int target) {
        set<PII> visited;
        visited.insert({0, 1});
        queue<PII> q;
        q.push({0, 1});
        int step = -1;
        while (!q.empty()) {
            int sz = SZ(q);
            step++;
            while (sz--) {
                auto [pos, speed] = q.front();
                q.pop();
                if (pos == target) return step;
                if (speed > 0) {
                    if (visited.find({pos + speed, speed * 2}) == end(visited)) {
                        visited.insert({pos + speed, speed * 2});
                        q.push({pos + speed, speed * 2});
                    }
                    if (visited.find({pos, -1}) == end(visited)) {
                        visited.insert({pos, -1});
                        q.push({pos, -1});
                    }
                } else {
                    if (visited.find({pos + speed, speed * 2}) == end(visited)) {
                        visited.insert({pos + speed, speed * 2});
                        q.push({pos + speed, speed * 2});
                    }
                    if (visited.find({pos, -1}) == end(visited)) {
                        visited.insert({pos, 1});
                        q.push({pos, 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    int res = s.racecar(4);
    vector<int> nums{-1,0,1,0,3,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    ll dp[2][2][4] = {0};
    dp[1][1][1] = 3;
    memset(dp, 0, sizeof(dp));
}