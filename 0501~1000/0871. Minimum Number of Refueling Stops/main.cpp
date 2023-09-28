/**
 * Source: t.ly/iIVqs
 * Date: 2023/9/26
 * Skill:
 * Runtime: 23 ms, faster than 52.96% of C++ online submissions
 * Memory Usage: 16.6 MB, less than 19.91% of C++ online submissions
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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target)
            return 0;
        sort(begin(stations), end(stations));
        int cur_pos = startFuel, res = 0, idx = 0, sz = stations.size();
        priority_queue<int> pq;
        while (cur_pos < target) {
            while (idx < sz && stations[idx][0] <= cur_pos)
                pq.push(stations[idx++][1]);
            if (pq.empty())
                return -1;
            res++;
            cur_pos += pq.top(); pq.pop();
        }
        return cur_pos >= target ? res : -1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {2, 10},
                             {1, 10},
                             {2, 3},
                             {6,10},
                             {4,3},
                             {8,6},
                             {5,8},
                             {7,6}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}