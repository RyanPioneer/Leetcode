/** 
 * Source: https://leetcode.com/problems/unique-number-of-occurrences/
 * Date: 2022/11/30
 * Skill: Counting Sort
 * Runtime: 0 ms, faster than 100.00% 
 * Memory Usage:  8 MB, less than 86.41%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= arr.length <= 1000
 *      -1000 <= arr[i] <= 1000
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        int i = 0, sz = arr.size();
        while (i < sz) {
            int count = 0, j = i;
            while (j<sz && arr[i] == arr[j])
                j++, count++;
            res.push_back(count);
            i += count;
        }
        sort(res.begin(), res.end());
        sz = res.size();
        for (int i = 0; i <sz-1; i++) {
            if (res[i] == res[i+1])
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