/**
 * Source: ibit.ly/t4x6l
 * Date: 2023/10/13
 * Skill:
 * Runtime: 2 ms, faster than 55.69% of C++ online submissions
 * Memory Usage: 12.05 MB, less than 29.44% of C++ online submissions
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
    int fillCups(vector<int>& amount) {
        int res = 0;
        priority_queue<int> pq;
        for (auto i: amount)
            if (i > 0)
                pq.push(i);
        while (!pq.empty()) {
            int cup1 = pq.top();
            pq.pop();
            if (pq.empty())
                return res + cup1;
            int cup2 = pq.top();
            pq.pop();
            if (pq.empty())
                return res + cup1;
            int num = cup2 - pq.top() + 1;
            res += num;
            if (cup1 - num > 0)
                pq.push(cup1 - num);
            if (cup2 - num > 0)
                pq.push(cup2 - num);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}