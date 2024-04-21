/**
 * Source: is.gd/u3MpDc
 * Date: 2024/4/21
 * Skill:
 * Ref:
 * Runtime: 23 ms, faster than 26.05% of C++ online submissions
 * Memory Usage: 16.53 MB, less than 64.52% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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

const int MX = 102;

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        vector<int> group(n);

        iota(begin(group), end(group), 0);
        sort(begin(logs), end(logs));

        function<int(int)> findGroup = [&](int id) {
            if (group[id] != id) {
                group[id] = findGroup(group[id]);
            }
            return group[id];
        };

        function<void(int, int)> merge = [&](int a, int b) {
            int ga = findGroup(a), gb = findGroup(b);
            if (ga != gb) group[max(ga, gb)] = min(ga, gb);
        };

        for (auto &i: logs) {
            merge(i[1], i[2]);
            bool check = true;
            for (int i = 1; i < n; i++) {
                if (findGroup(i) != findGroup(i - 1)) {
                    check = false;
                    break;
                }
            }
            if (check) return i[0];
        }
        return -1;
    }
};