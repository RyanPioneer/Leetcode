/**
 * Source: tinyurl.com/ykbb5wcx
 * Date: 2023/10/23
 * Skill:
 * Runtime: 139 ms, faster than 64.27% of C++ online submissions
 * Memory Usage: 67.34 MB, less than 50.45% of C++ online submissions
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
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(begin(buses), end(buses));
        sort(begin(passengers), end(passengers));
        int res = 1, idx = 0, sz = passengers.size();
        for (auto i: buses) {
            int num = capacity;
            while (num > 0 && idx < sz && passengers[idx] <= i) {
                if (idx == 0 || passengers[idx - 1] != passengers[idx] - 1)
                    res = passengers[idx] - 1;
                idx++;
                num--;
            }
            if (num > 0 && (idx == 0 || passengers[idx - 1] != i))
                res = i;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}