/** 
 * Source: https://leetcode.com/problems/find-players-with-zero-or-one-losses/
 * Date: 2022/11/28
 * Skill: 此題map優於unordered_map，因題目要求輸出要排序
 * Runtime: 648 ms, faster than 95.22%
 * Memory Usage:  162.1 MB, less than 88.98%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      All matches[i] are unique.
 *      1 <= winneri, loseri <= 10^5
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2);
        map<int, int> mymap;
        for (int i = 0; i < matches.size(); i++) {
            if (mymap.find(matches[i][0]) == mymap.end()) {
                mymap[matches[i][0]] = 0;
            }
            mymap[matches[i][1]]++;
        }
        for(auto iter = mymap.begin(); iter != mymap.end(); ++iter) {
            if (iter->second == 0)
                res[0].push_back(iter->first);
            else if (iter->second == 1)
                res[1].push_back(iter->first);
        }
        return res;
    }
};

int main() {
    Solution s;
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();