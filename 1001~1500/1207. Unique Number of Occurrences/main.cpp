/** 
 * Source: https://leetcode.com/problems/unique-number-of-occurrences/
 * Date: 2022/11/30
 * Skill: 
 * Runtime: 4 ms, faster than 69.41%
 * Memory Usage:  8.2 MB, less than 20.75%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= arr.length <= 1000
 *      -1000 <= arr[i] <= 1000
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> myMap;
        unordered_set<int> mySet;
        for (auto i : arr) 
            myMap[i]++;
        for (auto [first, second] : myMap) {
            if (mySet.find(second) == mySet.end())
                mySet.insert(second);
            else
                return false;
        }
        return true;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();