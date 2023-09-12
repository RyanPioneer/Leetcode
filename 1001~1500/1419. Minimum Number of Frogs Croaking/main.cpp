/**
 * Source: https://rb.gy/tubn2
 * Date: 2023/9/12
 * Skill:
 * Runtime: 22 ms, faster than 62.73% of C++ online submissions
 * Memory Usage: 9.41 MB, less than 9.39% of C++ online submissions
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
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> char2num = {{'c', 0},
                                             {'r', 1},
                                             {'o', 2},
                                             {'a', 3},
                                             {'k', 4}};
        int res = 0, cur_num = 0;
        vector<int> cnt(5, 0);
        for (auto c: croakOfFrogs) {
            int num = char2num[c];
            if (num == 0) {
                cur_num++;
                res = max(res, cur_num);
                cnt[num]++;
            } else {
                if (cnt[num - 1] == 0)
                    return -1;
                cnt[num - 1]--;
                cnt[num]++;
                if (num == 4)
                    cur_num--;
            }
        }
        for (int i = 0; i < 4; i++)
            if (cnt[i] > 0)
                return -1;
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
}