/**
 * Source: tinyurl.com/ypuqubyx
 * Date: 2023/10/21
 * Skill:
 * Runtime: 300 ms, faster than 37.95% of C++ online submissions
 * Memory Usage: 71.29 MB, less than 33.04% of C++ online submissions
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
        int res = 0, right = 0, sz = tiles.size();
        vector<int> presum(sz + 1, 0);
        for (int i = 0; i < sz; ++i)
            presum[i + 1] = presum[i] + tiles[i][1] - tiles[i][0] + 1;
        for (int i = 0; i < sz; ++i) {
            while (right + 1 < sz && tiles[right][1] - tiles[i][0] < carpetLen)
                right++;
            int cur_len = presum[right] - presum[i];
            if (right > i)
                cur_len += (tiles[right][0] - tiles[i][0] < carpetLen ? min(tiles[i][0] + carpetLen - 1, tiles[right][1]) - tiles[right][0] + 1 : 0);
            else
                cur_len = min(carpetLen, tiles[i][1] - tiles[i][0] + 1);
            res = max(res, cur_len);
        }
        return res;
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