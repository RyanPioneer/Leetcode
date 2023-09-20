/**
 * Source: t.ly/_E8Fv
 * Date: 2023/9/20
 * Skill:
 * Runtime: 162 ms, faster than 45.61% of C++ online submissions
 * Memory Usage: 11.29 MB, less than 13.18% of C++ online submissions
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
        unordered_map<int, int> state2idx;
        int res = 1;
        vector<int> cur_state(10, 0);
        state2idx[0] = -1;
        for (int i = 0; i < s.length(); i++) {
            int digit = s[i] - '0';
            cur_state[digit] = (cur_state[digit] + 1) % 2;
            int key = make_key(cur_state);
            if (state2idx.find(key) != state2idx.end())
                res = max(res, i - state2idx[key]);
            else
                state2idx[key] = i;
            for (int j = 0; j < 10; j++) {
                int k2 = key + (((key>>j)&1)==0 ? (1<<j) : -(1<<j));
                if (state2idx.find(k2) != state2idx.end())
                    res = max(res, i - state2idx[k2]);
            }
        }
        return res;
    }
    int make_key(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 1)
                num += (1<<i);
        return num;
    }
};

int main() {

}