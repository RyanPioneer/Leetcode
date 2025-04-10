/**
 * Source: t.ly/OJ5Qs
 * Date: 2025/3/31
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 198.08 MB, less than 58.18% of C++ online submissions
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
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int total = accumulate(nums.begin(), nums.end(), 0ll), sz = nums.size(), loss = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while (op1 || op2) {
            int num = pq.top();
            pq.pop();
            if (op2 > 0 && (num / 2 <= k || op1 == 0)) {
                loss += k;
                op2--;
                pq.push(num - k);
            } else if (op1 > 0) {
                loss += num / 2;
                op1--;
                pq.push(num - num / 2);
            } else {
                break;
            }
        }
        return total - loss;
    }
};
2 4 3 3 2 1