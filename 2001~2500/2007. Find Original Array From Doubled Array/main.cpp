/**
 * Source: https://rb.gy/zqgqs
 * Date: 2023/9/15
 * Skill:
 * Runtime: 261 ms, faster than 85.26% of C++ online submissions
 * Memory Usage: 140.52 MB, less than 81.99% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res, empty;
        if (changed.size() % 2 == 1)
            return res;
        sort(begin(changed), end(changed));
        unordered_map<int, int> num2cnt;
        int sz = changed.size();
        for (auto i: changed) {
            if (i % 2 == 1 || num2cnt[i / 2] == 0)
                num2cnt[i]++;
            else {
                num2cnt[i / 2]--;
                res.push_back(i / 2);
            }
        }
        return (res.size() * 2 == sz) ? res : empty;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
}