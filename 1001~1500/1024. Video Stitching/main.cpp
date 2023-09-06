/**
 * Source: https://rb.gy/0891a
 * Date: 2023/9/6
 * Skill:
 * Runtime: 4 ms, faster than 46.40% of C++ online submissions
 * Memory Usage: 7.83 MB, less than 40.48% of C++ online submissions
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


class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(begin(clips), end(clips), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });
        int res = 1, right = clips[0][1], next_right = clips[0][1];
        if (clips[0][0] > 0)
            return -1;
        if (right >= time)
            return 1;
        for (int i = 1; i < clips.size(); i++) {
            if (clips[i][0] <= right)
                next_right = max(next_right, clips[i][1]);
            else {
                if (next_right < clips[i][0])
                    return -1;
                else {
                    res++;
                    right = next_right;
                    next_right = max(next_right, clips[i][1]);
                }
            }
            if (next_right >= time)
                return res + 1;
        }
        return -1;
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
    string word1 = "aa", word2 = "ab";
}