/**
 * Source: jpeg.ly/dfWm1
 * Date: 2024/1/14
 * Skill:
 * Ref:
 * Runtime: 391 ms, faster than 6.00% of C++ online submissions
 * Memory Usage: 194.68 MB, less than 5.00% of C++ online submissions
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


class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = SZ(nums), step = 0;
        list<int> List;
        unordered_map<int, list<int>::iterator> idx2iter;
        for (int i = 0; i < n; ++i) {
            List.push_back(i);
            idx2iter[i] = prev(end(List));
        }
        queue<int> q;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                q.push(i);
            }
        }
        vector<int> cand;
        while (!q.empty()) {
            int sz = SZ(q);
            cand.clear();
            while (sz--) {
                auto it = idx2iter[q.front()];
                q.pop();
                if (next(it) != end(List) && (cand.empty() || *next(it) != cand.back())) {
                    cand.push_back(*next(it));
                }
                List.erase(it);
            }
            for (auto &i: cand) {
                auto it = idx2iter[i];
                if (nums[i] < nums[*prev(it)]) {
                    q.push(i);
                }
            }
            step++;
        }
        return step;
    }
};