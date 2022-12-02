/** 
 * Source: https://leetcode.com/problems/sum-of-subarray-minimums/
 * Date: 2022/11/25
 * Skill: Monotonic Stack
 * Runtime: 93 ms, faster than 97.63%
 * Memory Usage: 44 MB, less than 19.70%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= arr.length <= 3 * 10^4
 */

#include <iostream>
#include <vector>
#include <utility>
#include <stack> 

#define MOD 1000000007

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int res = 0;
        int sz = arr.size();
        vector<unsigned int> left(sz), right(sz);
        stack<pair<int,int>> mystack;
        for (int i = 0; i < sz; i++) {
            int count = 1;
            while (!mystack.empty() && arr[i] <= mystack.top().first) {
                count += mystack.top().second;
                mystack.pop();
            }
            left[i] = count;
            pair<int,int> p(arr[i], count);
            mystack.push(p);
        }
        while (!mystack.empty())mystack.pop();
        for (int i = sz-1; i >= 0; i--) {
            int count = 1;
            while (!mystack.empty() && arr[i] < mystack.top().first) {
                count += mystack.top().second;
                mystack.pop();
            }
            right[i] = count;
            pair<int,int> p(arr[i], count);
            mystack.push(p);
        }
        for (int i = 0; i < sz; i++) {
            res = (res+arr[i]*left[i]%MOD*right[i]%MOD)%MOD;
        }
        return res;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();