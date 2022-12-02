/**
 * Source: https://leetcode.com/problems/group-anagrams/
 * Date: 2022/7/12
 * Skill: map
 * Runtime:
 * Memory Usage:
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,int> mymap; 
        vector<vector<string>> ans;
        int index = 0;
        for (auto i:strs) {
            vector<int> nums(26, 0);
            for (auto j:i)
                nums[j-'a']++;
            if (mymap.find(nums) == mymap.end()) {
                mymap[nums] = index++;
                vector<string> vec;
                vec.push_back(i);
                ans.push_back(vec);
            } else {
                ans[mymap[nums]].push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution s;
    vector<vector<string>> ans = s.groupAnagrams(strs);
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();