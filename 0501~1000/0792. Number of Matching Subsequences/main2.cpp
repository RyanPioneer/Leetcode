/**
 * Source: https://rb.gy/lhu1v
 * Date: 2023/9/13
 * Skill:
 * Runtime: 861 ms, faster than 9.09% of C++ online submissions
 * Memory Usage: 403.96 MB, less than 5.21% of C++ online submissions
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
        vector<vector<int>> char2pos(s.length(), vector<int>(26, -1));
        char2pos[s.length() - 1][s[s.length() - 1] - 'a'] = s.length() - 1;
        for (int i = s.length() - 2; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (s[i] - 'a' == j)
                    char2pos[i][j] = i;
                else
                    char2pos[i][j] = char2pos[i + 1][j];
            }
        }
        int res = 0, sz = s.length();
        for (auto w: words) {
            int flag = true, pos = -1;
            for (auto c: w) {
                if (pos == sz - 1) {
                    flag = false;
                    break;
                }
                int next_pos = char2pos[pos + 1][c - 'a'];
                if (next_pos == -1) {
                    flag = false;
                    break;
                }
                pos = next_pos;
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