/**
 * Source: is.gd/cU9Gkb
 * Date: 2023/12/1
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 95.38% of C++ online submissions
 * Memory Usage: 8.35 MB, less than 92.49% of C++ online submissions
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


class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const int base = 6;
        unordered_set<int> visited;
        vector<int> swap[6];
        swap[0] = {1, 3};
        swap[1] = {0, 2, 4};
        swap[2] = {1, 5};
        swap[3] = {0, 4};
        swap[4] = {1, 3, 5};
        swap[5] = {2, 4};
        int initial_state = 0, final_state = 0, power = 1, step = -1, state[6];
        for (int i = 1; i <= 6; i++) {
            if (i < 6) final_state += i * power;
            initial_state += board[(i - 1) / 3][(i - 1) % 3] * power;
            power *= base;
        }
        if (initial_state == final_state) return 0;
        visited.insert(initial_state);
        queue<int> q;
        q.push(initial_state);
        while (!q.empty()) {
            int sz = SZ(q);
            step++;
            while (sz--) {
                int cur_state = q.front();
                q.pop();
                if (cur_state == final_state) return step;
                int tmp = cur_state, zero;
                for (int i = 0; i < 6; i++) {
                    state[i] = tmp % base;
                    if (state[i] == 0) zero = i;
                    tmp /= base;
                }
                for (auto &i: swap[zero]) {
                    int next_state = cur_state + state[i] * (pow(6, zero) - pow(6, i));
                    if (visited.find(next_state) != visited.end()) continue;
                    q.push(next_state);
                    visited.insert(next_state);
                }
            }
        }
        return -1;
    }
};