/**
 * Source: twtr.to/bIHjK
 * Date: 2023/11/21
 * Skill: farthest greater element
 * Ref:
 * Runtime: 31 ms, faster than 26.70% of C++ online submissions
 * Memory Usage: 25.91 MB, less than 5.18% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
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


#define SZ(X) ((int)(X).size())
using namespace std;
typedef pair<int, int> PII;


class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int diff = 0, sz = SZ(hours);
        vector<PII> pos;
        for (int i = 0; i < sz; i++) {
            diff += (hours[i] > 8 ? 1 : -1);
            pos.push_back({diff, i});
        }
        sort(begin(pos), end(pos));

        int res = 0, left = sz, prev_diff = pos[0].first;
        vector<int> buffer;
        for (int i = 0; i < SZ(hours); i++) {
            if (pos[i].first != prev_diff) {
                while (!buffer.empty()) {
                    left = min(left, buffer.back());
                    buffer.pop_back();
                }
            }
            prev_diff = pos[i].first;
            buffer.push_back(pos[i].second);
            if (pos[i].first > 0) res = max(res, pos[i].second + 1);
            else res = max(res, pos[i].second - left);
        }
        return res;
    }
};