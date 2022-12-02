/** 
 * Source: https://leetcode.com/problems/sum-of-subarray-minimums/
 * Date: 2022/11/25
 * Skill: DP
 * Runtime: TLE
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= arr.length <= 3 * 10^4
 */

#include <iostream>
#include <vector>
#include <utility>
#include <string> 

#define MOD 1000000007

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int res = 0, sz = arr.size();
        vector<int> vec(sz);
        for (int i = 0; i < sz; i++) {
            vec[i] = arr[i];
            res = (res+vec[i])%MOD;
        }
        for (int i = 1; i < sz; i++) {
            for (int j = 0; j+i < sz; j++) {
                vec[j] = (arr[j+i] < vec[j]) ? arr[j+i] : vec[j];
                res = (res+vec[j])%MOD;
            }
        }
        return res;
    }
};

int main() {
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();