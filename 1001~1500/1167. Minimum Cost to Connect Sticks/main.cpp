/**
 * Source: ibit.ly/2-GYe
 * Date: 2024/7/1
 * Skill:
 * Ref:
 * Runtime: 65 ms, faster than 49.01% of C++ online submissions
 * Memory Usage: 27.63 MB, less than 29.47% of C++ online submissions
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
    int connectSticks(vector<int>& sticks) {
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &i: sticks) {
            pq.push(i);
        }
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            res += a + b;
            pq.push(a + b);
        }
        return res;
    }
};