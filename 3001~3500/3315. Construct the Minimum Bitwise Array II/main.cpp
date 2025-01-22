/**
 * Source: is.gd/7AWJrf
 * Date: 2025/1/22
 * Skill:
 * Ref: 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 28.35 MB, less than 30.77% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;

#define ll long long


class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (auto &i: nums) {
            if (i % 2 == 0) {
                res.push_back(-1);
            } else {
                int del = 1, j = i/2;
                while (j % 2) {
                    j /= 2;
                    del *= 2;
                }
                res.push_back(i - del);
            }
        }
        return res;
    }
};
