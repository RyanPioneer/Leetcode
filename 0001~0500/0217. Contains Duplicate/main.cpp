/** 
 * Source: https://leetcode.com/problems/contains-duplicate/
 * Date: 2021/7/17
 * Skill: Hash Table
 * * Internally unordered_map is implemented using Hash Table
 * Runtime: 33 ms, faster than 52.31% of C++ online submissions
 * Memory Usage: 20 MB, less than 71.44% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints: 
 * 
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>myMap;
        for (auto i: nums) {
            if (myMap.count(i))
                return true;
            else
                myMap[i] = 1;
        }
        return false;
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