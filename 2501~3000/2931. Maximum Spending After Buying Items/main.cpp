/**
 * Source: t.ly/QC1up
 * Date: 2023/11/12
 * Skill:
 * Runtime: 195 ms, faster than 66.67% of C++ online submissions
 * Memory Usage: 52.07 MB, less than 61.90% of C++ online submissions
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

typedef pair<int, int> pairs;


class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        int m = values.size(), n = values[0].size(), day = 0;
        ll res = 0;
        for (int i = 0; i < m; i++) {
            pq.push({values[i][n - 1], i});
            values[i].pop_back();
        }
        while (!pq.empty()) {
            day++;
            auto [val, idx] = pq.top();
            pq.pop();
            res += (ll)day * val;
            if (!values[idx].empty()) {
                pq.push({values[idx].back(), idx});
                values[idx].pop_back();
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}