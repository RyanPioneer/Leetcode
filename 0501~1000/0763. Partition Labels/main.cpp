/** 
 * Source: https://leetcode.com/problems/partition-labels/
 * Date: 2022/11/29
 * Skill: Greedy Algo
 * Runtime: 4 ms, faster than 82.61%
 * Memory Usage: 6.7 MB, less than 68.62%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>   

using namespace std;

class Solution {
public:
    unordered_map<char,int> mymap;
    vector<int> partitionLabels(string s) {
        int len = s.length();
        vector<int> res;
        for (int i = 0; i < len; i++)
            mymap[s[i]] = i;
        for (int prev = -1, cur = 0, i = 0; i < len; i++) {
            cur = max(cur, mymap[s[i]]);
            if (i == cur) {
                res.push_back(cur-prev);
                prev = i;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "vhaagbqkaq";
    vector<int> res = s.partitionLabels(str);
    for (auto i : res) {
        cout << i << endl;
    }
}


static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();