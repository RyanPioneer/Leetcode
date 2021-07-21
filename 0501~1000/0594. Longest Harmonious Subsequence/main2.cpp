/** 
 * Source: https://leetcode.com/problems/longest-harmonious-subsequence/
 * Date: 2021/7/21
 * Skill: Hashmap
 * Runtime: 140 ms, faster than 18.44% of C++ online submissions
 * Memory Usage: 41.7 MB, less than 22.21% of C++ online submissions
 * Time complexity: O(n) 
 * Space complexity: O(n)
 * Constraints: 
 *      1 <= nums.length <= 2 * 10^4
 *      -10^9 <= nums[i] <= 10^9
 */

#include<iostream>
#include<vector>
#include<map>   //* By default, a Map in C++ is sorted in increasing order based on its key
#include<cstdlib>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> myMap;
        int ans = 0;
        for (auto i: nums) {
            if (!myMap.count(i)) myMap[i] = 1;
            else myMap[i]++;
            int temp = 0;
            if (myMap.count(i+1))
                temp = myMap[i+1];
            if (myMap.count(i-1))
                temp = (temp > myMap[i-1]) ? temp : myMap[i-1];
            if (temp) ans = (ans > myMap[i]+temp) ? ans : myMap[i]+temp;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v1 = {1,3,2,2,5,2,3,7};
    cout<<s.findLHS(v1);
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();