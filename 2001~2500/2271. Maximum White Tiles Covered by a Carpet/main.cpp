/**
 * Source: tinyurl.com/ypuqubyx
 * Date: 2023/10/21
 * Skill:
 * Runtime: 316 ms, faster than 22.47% of C++ online submissions
 * Memory Usage: 82.16 MB, less than 6.61% of C++ online submissions
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
#include <functional>
#include <list>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        deque<pairs> q;
        int res = 0, cur_len = 0;
        for (auto t: tiles) {
            if (t[1] - t[0] >= carpetLen - 1 || res >= carpetLen)
                return carpetLen;
            while (!q.empty() && q.front().second + carpetLen <= t[1]) {
                cur_len -= q.front().second - q.front().first + 1;
                q.pop_front();
            }
            if (!q.empty() && q.front().first + carpetLen <= t[1]) {
                int new_head = t[1] - carpetLen + 1;
                cur_len -= new_head - q.front().first;
                q.front().first = new_head;
            }
            cur_len += t[1] - t[0] + 1;
            res = max(res, cur_len);
            q.push_back({t[0], t[1]});
        }
        return res > carpetLen ? carpetLen : res;
    }
};


int main() {
    Solution s;
    vector<int> nums{5,4,6};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    int res = s.maximumWhiteTiles(arr, 10);
    cout << res << endl;
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}