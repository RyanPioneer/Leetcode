/**
 * Source: t.ly/_SlL4
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 1031 ms, faster than 20.80% of C++ online submissions
 * Memory Usage: 264.72 MB, less than 16.45% of C++ online submissions
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
typedef pair<int, int> PII;
#define MK make_pair

const int offset = 3000;


class Solution {
public:
    int minKnightMoves(int x, int y) {
        int dir[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        int res = -1;
        PII pos = MK(0, 0);

        unordered_set<int> Set;
        Set.insert(pos.first * offset + pos.second);
        queue<PII> q;
        q.push(pos);
        while (!q.empty()) {
            res++;
            int sz = q.size();
            while (sz--) {
                PII cur = q.front();
                q.pop();
                if (cur.first == x && cur.second == y) {
                    return res;
                }
                for (int i = 0; i < 8; i++) {
                    int x = cur.first + dir[i][0], y = cur.second + dir[i][1];
                    int hash = x * offset + y;
                    if (Set.find(hash) != end(Set)) continue;
                    Set.insert(hash);
                    q.push(MK(x, y));
                }
            }
        }
        return -1;
    }
};