/**
 * Source: twtr.to/bIHjK
 * Date: 2023/11/21
 * Skill:
 * Ref:
 * Runtime: 48 ms, faster than 12.37% of C++ online submissions
 * Memory Usage: 25.61 MB, less than 5.11% of C++ online submissions
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
        int diff = 0, res = 0, right = -1;
        priority_queue<PII> pq;
        for (int i = 0; i < SZ(hours); i++) {
            diff += (hours[i] > 8 ? 1 : -1);
            pq.push({diff, i});
        }
        vector<int> buffer;
        while (!pq.empty()) {
            int prev = INT32_MAX;
            while (!pq.empty() && (prev == INT32_MAX || pq.top().first == prev)) {
                prev = pq.top().first;
                buffer.push_back(pq.top().second);
                pq.pop();
                if (prev > 0) res = max(res, buffer.back() + 1);
                if (right > buffer.back()) res = max(res, right - buffer.back());
            }
            while (!buffer.empty()) {
                right = max(right, buffer.back());
                buffer.pop_back();
            }
        }
        return res;
    }
};