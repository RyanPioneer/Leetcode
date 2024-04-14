/**
 * Source: is.gd/TylZ69
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 271 ms, faster than 67.66% of C++ online submissions
 * Memory Usage: 141.73 MB, less than 61.26% of C++ online submissions
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
typedef pair<int, int> PII;


class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<PII, vector<PII>, greater<>> pq;

        for (int i = 0; i < n; ++i) pq.push({nums[i], i});

        vector<ll> res;
        ll total = accumulate(begin(nums), end(nums), 0ll);

        for (auto &q: queries) {
            if (!marked[q[0]]) total -= nums[q[0]];
            marked[q[0]] = true;
            while (q[1] && !pq.empty()) {
                if (marked[pq.top().second]) {
                    pq.pop();
                    continue;
                }
                q[1]--;
                total -= nums[pq.top().second];
                marked[pq.top().second] = true;
            }
            res.push_back(total);
        }
        return res;
    }
};