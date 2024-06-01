/**
 * Source: t.ly/ska7d
 * Date: 2024/6/1
 * Skill:
 * Ref:
 * Runtime: 2 ms, faster than 74.33% of C++ online submissions
 * Memory Usage: 15.31 MB, less than 18.67% of C++ online submissions
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


class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int state = 0, day;
        vector<int> res;
        for (int i = 0; i < 8; i++) {
            if (cells[i]) {
                state |= 1 << i;
            }
        }

        unordered_set<int> Set;
        unordered_map<int, int> day2state, state2day;
        day2state[0] = state;
        state2day[state] = 0;

        for (day = 1; day <= n; day++) {
            int nextState = 0;
            for (int j = 1; j < 7; j++) {
                if (((state >> (j - 1)) & 1) == ((state >> (j + 1)) & 1)) {
                    nextState |= 1 << j;
                }
            }
            if (state2day.find(nextState) != end(state2day)) {
                int diff = day - state2day[nextState];
                for (int i = 0; i < 8; i++) {
                    res.push_back((day2state[state2day[nextState] + (n - state2day[nextState]) % diff] >> i) & 1);
                }
                return res;
            }
            day2state[day] = state = nextState;
            state2day[state] = day;
        }

        for (int i = 0; i < 8; i++) {
            res.push_back((day2state[n] >> i) & 1);
        }
        return res;
    }
};