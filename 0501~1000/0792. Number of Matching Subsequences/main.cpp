/**
 * Source: https://rb.gy/lhu1v
 * Date: 2023/9/13
 * Skill:
 * Runtime: 183 ms, faster than 65.79% of C++ online submissions
 * Memory Usage: 53.80 MB, less than 41.21% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> char2pos(26);
        for (int i = 0; i < s.length(); i++)
            char2pos[s[i] - 'a'].push_back(i);
        int res = 0;
        for (auto w: words) {
            int pos = -1;
            bool flag = true;
            for (auto c: w) {
                auto next_pos = upper_bound(begin(char2pos[c - 'a']), end(char2pos[c - 'a']), pos);
                if (next_pos == end(char2pos[c - 'a'])) {
                    flag = false;
                    break;
                } else
                    pos = *next_pos;
            }
            if (flag)
                res++;
        }
        return res;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    cout << 8 % -2;
}