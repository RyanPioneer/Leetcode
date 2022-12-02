/** 
 * Source: https://leetcode.com/problems/number-of-unequal-triplets-in-array/
 * Date: 2022/11/20
 * Skill: 
 * Runtime: 0 ms, faster than 100.00% 
 * Memory Usage: 8.9 MB, less than 18.18%
 * Time complexity: O(n)
 * Space complexity: 
 * Constraints: 
 *      
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string> 
using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int,int>mymap;
        for (auto i:nums) 
            mymap[i]++;
        int res = 0, left = 0, right = nums.size();
        for (auto [n,cnt]:mymap) {
            right -= cnt;
            res += left * cnt * right;
            left += cnt;
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