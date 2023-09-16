/**
 * Source: https://rb.gy/ckkny
 * Date: 2023/9/16
 * Skill:
 * Runtime: 736 ms, faster than 5.11% of C++ online submissions
 * Memory Usage: 139.60 MB, less than 41.35% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> key2num, num2key;
        for (auto i: operations) {
            if (num2key.find(i[0]) != num2key.end()) {
                int key = num2key[i[0]];
                key2num[key] = i[1];
                num2key[i[1]] = key;
                num2key.erase(num2key.find(i[0]));
            } else {
                key2num[i[0]] = i[1];
                num2key[i[1]] = i[0];
            }
        }
        for (auto& i: nums)
            if (key2num.find(i) != key2num.end())
                i = key2num[i];
        return nums;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,4};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};

}