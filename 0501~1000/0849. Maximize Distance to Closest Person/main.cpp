/**
 * Source: t.ly/DvQp3
 * Date: 2024/5/30
 * Skill:
 * Ref:
 * Runtime: 6 ms, faster than 83.32% of C++ online submissions
 * Memory Usage: 19.35 MB, less than 70.57% of C++ online submissions
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


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0, n = seats.size(), pos = 0;
        while (seats[pos] == 0) pos++;
        res = max(0, pos);
        while (pos < n-1) {
            int nxt = pos + 1;
            while (nxt < n && seats[nxt] == 0) nxt++;
            if (nxt == n) break;
            res = max(res, (nxt - pos) / 2);
            pos = nxt;
        }
        res = max(res, n - pos - 1);
        return res;
    }
};