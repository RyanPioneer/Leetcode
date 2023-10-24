/**
 * Source: tinyurl.com/yol9gfby
 * Date: 2023/10/24
 * Skill:
 * Runtime: 767 ms, faster than 14.80% of C++ online submissions
 * Memory Usage: 404.60 MB, less than 5.38% of C++ online submissions
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
        vector<vector<int>> score, children(nums.size());
        for (int i = 1; i < nums.size(); i++)
            children[parents[i]].push_back(i);
        vector<int> res(nums.size(), INT32_MAX);
        for (int i = 0; i < nums.size(); i++)
            score.push_back({nums[i], i});
        sort(score.begin(), score.end());
        int num = 1;
        for (int i = 0; i < score.size(); i++) {
            if (score[i][0] != num)
                break;
            int cur = parents[score[i][1]], child = score[i][1];
            queue<int> q;
            for (auto &j: children[child])
                if (res[j] > num)
                    q.push(j);
            children[child].clear();
            while (cur != -1) {
                for (auto &j: children[cur])
                    if (j != child && res[j] > num)
                        q.push(j);
                if (children[cur].size() > 1 || (children[cur].size() == 1 && children[cur][0] == child)) {
                    children[cur].clear();
                    children[cur].push_back(child);
                }
                else
                    children[cur].clear();
                child = cur;
                cur = parents[cur];
                parents[child] = -1;
            }
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                res[node] = score[i][0];
                for (auto &j: children[node])
                    q.push(j);
                children[node].clear();
            }
            num++;
        }
        for (int i = 0; i < res.size(); i++)
            if (res[i] == INT32_MAX)
                res[i] = num;
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