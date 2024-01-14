/**
 * Source: jpeg.ly/dfWm1
 * Date: 2024/1/14
 * Skill:
 * Ref:
 * Runtime: 137 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 89.01 MB, less than 26.33% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;
typedef pair<int, int> PII;


class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = SZ(nums), step = 0, removed[MX] = {0}, next[MX] = {1};
        queue<PII> q;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                q.push({i - 1, i});
            }
            next[i] = i + 1;
        }
        while (!q.empty()) {
            int sz = SZ(q);
            while (sz--) {
                auto [l, r] = q.front();
                q.pop();
                if (removed[l]) continue;
                removed[r] = true;
                int nxt = next[r];
                while (nxt != n && removed[nxt]) nxt = next[nxt];
                next[r] = nxt;
                if (nxt != n && nums[l] > nums[nxt]) {
                    q.push({l, nxt});
                }
            }
            step++;
        }
        return step;
    }
};