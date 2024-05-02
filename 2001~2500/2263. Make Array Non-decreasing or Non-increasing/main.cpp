/**
 * Source: t.ly/J7Wc_
 * Date: 2024/5/2
 * Skill:
 * Ref: t.ly/lJ1OD
 * Runtime: 7 ms, faster than 77.22% of C++ online submissions
 * Memory Usage: 13.51 MB, less than 91.14% of C++ online submissions
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


class Solution {
public:
    int convertArray(vector<int>& nums) {
        function<int()> helper = [&]() {
            int num = 0;
            priority_queue<int> q;
            for (auto &i: nums) {
                if (!q.empty() && q.top() > i) {
                    num += q.top() - i;
                    q.pop();
                    q.push(i);
                }
                q.push(i);
            }
            return num;
        };

        int res = helper();
        reverse(begin(nums), end(nums));
        res = min(res, helper());
        return res;
    }
};