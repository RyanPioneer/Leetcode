/**
 * Source: t.ly/kmJAz
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 117 ms, faster than 75.00% of C++ online submissions
 * Memory Usage: 102.03 MB, less than 28.85% of C++ online submissions
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
    int makePrefSumNonNegative(vector<int>& nums) {
        int res = 0;
        long long curSum = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto &i: nums) {
            curSum += i;
            pq.push(i);
            if (curSum < 0) {
                int num = pq.top();
                pq.pop();
                res++;
                curSum -= num;
            }
        }
        return res;
    }
};