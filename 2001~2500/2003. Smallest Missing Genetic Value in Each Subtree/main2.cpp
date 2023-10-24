/**
 * Source: tinyurl.com/yol9gfby
 * Date: 2023/10/24
 * Skill:
 * Runtime: 361 ms, faster than 36.77% of C++ online submissions
 * Memory Usage: 155.98 MB, less than 78.48% of C++ online submissions
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
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> children[100001];
        int num1 = (nums[0] == 1 ? 0 : -1);
        for (int i = 1; i < nums.size(); i++) {
            children[parents[i]].push_back(i);
            if (nums[i] == 1)
                num1 = i;
        }
        if (num1 == -1) {
            fill(begin(res), end(res), 1);
            return res;
        }
        unordered_set<int> visited;
        visited.insert(1);
        int cur = num1, child = -1, cur_low = 1;
        queue<int> q;
        while (cur != -1) {
            visited.insert(nums[cur]);
            for (auto i: children[cur]) {
                if (i != child) {
                    q.push(i);
                    while (!q.empty()) {
                        int a = q.front();
                        q.pop();
                        res[a] = 1;
                        visited.insert(nums[a]);
                        for (auto j: children[a])
                            q.push(j);
                    }
                }
            }
            while (visited.find(cur_low) != visited.end())
                cur_low++;
            res[cur] = cur_low;
            child = cur;
            cur = parents[cur];
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3}, nums2{5,4,6,2,1,3};
    vector<int> res = s.smallestMissingValueSubtree(nums, nums2);
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}