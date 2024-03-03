/**
 * Source: is.gd/kiNV3A
 * Date: 2024/3/3
 * Skill:
 * Ref:
 * Runtime: 216 ms, faster than 71.43% of C++ online submissions
 * Memory Usage: 98.60 MB, less than 42.86% of C++ online submissions
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
#define ll long long


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        ll n1, n2, res = 0;
        for (auto &i: nums) pq.push(i);
        while (pq.size() > 1 && pq.top() < k) {
            n1 = pq.top();
            pq.pop();
            n2 = pq.top();
            pq.pop();
            res++;
            pq.push(n1 * 2 + n2);
        }
        return res;
    }
};