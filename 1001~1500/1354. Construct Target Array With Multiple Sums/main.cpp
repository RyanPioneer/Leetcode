/**
 * Source: ibit.ly/xfIVa
 * Date: 2023/10/13
 * Skill:
 * Runtime: 26 ms, faster than 93.16% of C++ online submissions
 * Memory Usage: 30.37 MB, less than 47.90% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        ll cur_sum = 0;
        for (auto i: target) {
            cur_sum += i;
            pq.push(i);
        }
        while (pq.top() != 1) {
            int num = pq.top();
            pq.pop();
            ll others = cur_sum - num;
            if (num < 1 || others >= num || others == 0)
                return false;
            int prev = num % others != 0 ? num % others : others;
            cur_sum += prev - num;
            pq.push(prev);
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}