/**
 * Source: is.gd/fL4PzO
 * Date: 2023/11/29
 * Skill:
 * Ref:
 * Runtime: 30 ms, faster than 51.15% of C++ online submissions
 * Memory Usage: 8.62 MB, less than 65.44% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
typedef pair<int, int> PII;
const int MX = 1e4 + 1;


class Solution {
public:
    int racecar(int target) {
        int bit_max = 32 - __builtin_clz(target);
        int boundary = 1 << bit_max;
        int visited[boundary * 2 + 1];
        fill(visited, visited + boundary * 2 + 1, INT32_MAX);
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, target});
        while (!pq.empty()) {
            auto [step, targ] = pq.top();
            pq.pop();
            if (targ == 0) return step - 1;
            if (step >= visited[targ + boundary]) continue;
            visited[targ + boundary] = step;
            for (int i = 0; i <= bit_max; i++) {
                int step2 = step + i + 1, targ2 = (1 << i) - 1 - targ;
                if (abs(targ2) <= boundary && visited[targ2 + boundary] > step2) {
                    pq.push({step2, targ2});
                }
            }
        }
        return -1;
    }
};