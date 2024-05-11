/**
 * Source: t.ly/XUPnx
 * Date: 2024/5/10
 * Skill:
 * Ref:
 * Runtime: 137 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 104.56 MB, less than 100.00% of C++ online submissions
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
const int MX = 17;


class Solution {
public:
    vector<int> maxHammingDistances(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> res;
        queue<int> q;
        int dist[1 << MX];
        fill(dist, dist + (1 << m), -1);
        for (int i = 0; i < n; i++) {
            int rev = ((1 << m) - 1) ^ nums[i];
            q.push(rev);
            dist[rev] = 0;
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < m; i++) {
                int r = cur ^ (1 << i);
                if (dist[r] == -1) {
                    dist[r] = dist[cur] + 1;
                    q.push(r);
                }
            }
        }
        for (auto &i: nums) {
            res.push_back(m - dist[i]);
        }
        return res;
    }
};