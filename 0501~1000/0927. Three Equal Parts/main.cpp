/** 
 * Source: https://leetcode.com/problems/three-equal-parts/
 * Date: 2021/7/17
 * Skill: 
 * Runtime: 32 ms, faster than 91.57% of C++ online submissions
 * Memory Usage: 38.8 MB, less than 93.37% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Constraints: 
 *      3 <= arr.length <= 3 * 10^4
 *      arr[i] is 0 or 1
 *  * Each part has to have the same number of ones in their representation
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int count = 0, ml, zeros = 0, sz = arr.size();
        for (auto i: arr) 
            if (i == 1) 
                count++;
        if (count == 0)
            return {0, (int)arr.size()-1};
        if (count %3 != 0)
            return {-1, -1};
        while (!arr[sz-1-zeros])
            zeros++;
        int num = count/3, ll = 0;
        while (!arr[ll])
            ll++;
        int lr = ll;
        while (num) 
            if (arr[lr++])
                num--;
        for (int i = zeros; i > 0; i--) {
            if (arr[lr++])
                return {-1, -1};
        }
        ml = lr, lr--;
        while (!arr[ml])
            ml++;
        for (int i = ll; i <= lr; i++) {
            if (arr[ml++] != arr[i])
                return {-1, -1};
        }
        int right = ml;
        while (!arr[ml])
            ml++;
        for (int i = ll; i <= lr; i++) {
            if (arr[ml++] != arr[i])
                return {-1, -1};
        }
        return {lr, right};
    }
};

int main() {
    vector<int> v1 = {1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0};
    Solution s;
    vector<int> ans = s.threeEqualParts(v1);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();