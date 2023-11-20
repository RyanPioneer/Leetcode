/**
 * Source: twtr.to/6qq8C
 * Date: 2023/11/19
 * Skill:
 * Runtime: 76 ms, faster than 75.81% of C++ online submissions
 * Memory Usage: 53.96 MB, less than 84.16% of C++ online submissions
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


class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        ll cur_sum = 0, pq_sum = 0, sz = heights.size();
        for (int i = 1; i < sz; i++) {
            if (heights[i] <= heights[i - 1]) continue;
            int diff = heights[i] - heights[i - 1];
            cur_sum += diff;
            if (pq.size() < ladders) {
                pq.push(diff);
                pq_sum += diff;
            } else if (ladders > 0 && pq.top() < diff) {
                pq_sum += diff - pq.top();
                pq.push(diff);
                pq.pop();
            }
            if (cur_sum - pq_sum > bricks) return i - 1;
        }
        return sz - 1;
    }
};