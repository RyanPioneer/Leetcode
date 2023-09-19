/**
 * Source: t.ly/_E8Fv
 * Date: 2023/9/19
 * Skill:
 * Runtime: 451 ms, faster than 25.76% of C++ online submissions
 * Memory Usage: 12.81 MB, less than 7.69% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<string, int> state2idx;
        int res = 1;
        string cur_state = "0000000000";
        state2idx[cur_state] = -1;
        for (int i = 0; i < s.length(); i++) {
            int digit = s[i] - '0';
            cur_state[digit] = cur_state[digit] == '0' ? '1' : '0';
            if (state2idx.find(cur_state) != state2idx.end())
                res = max(res, i - state2idx[cur_state]);
            else
                state2idx[cur_state] = i;
            for (int j = 0; j < 10; j++) {
                string next_state = cur_state;
                next_state[j] = cur_state[j] == '0' ? '1' : '0';
                if (state2idx.find(next_state) != state2idx.end())
                    res = max(res, i - state2idx[next_state]);
            }
        }
        return res;
    }
};

int main() {

}