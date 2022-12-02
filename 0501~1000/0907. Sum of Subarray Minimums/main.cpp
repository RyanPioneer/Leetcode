/** 
 * Source: https://leetcode.com/problems/sum-of-subarray-minimums/
 * Date: 2022/11/25
 * Skill: 
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
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            int min = arr[i];
            res = (res+min)%MOD;
            for (int j = i+1; j < arr.size(); j++) {
                if (arr[j] < min) 
                    min = arr[j];
                res = (res+min)%MOD;
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