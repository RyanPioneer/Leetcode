/** 
 * Source: https://leetcode.com/problems/add-minimum-number-of-rungs/
 * Date: 2021/7/21
 * Skill: 
 * Runtime: 48 ms, faster than 99.91% of C++ online submissions
 * Memory Usage: 53.6 MB, less than 99.91% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Constraints: 
 *      1 <= rungs.length <= 10^5
 *      1 <= rungs[i], dist <= 10^9
 *      rungs is strictly increasing.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int pos = 0, ans = 0;
        for (auto i : rungs) {
            if (i - pos > dist) {
                ans += (i - pos)/dist;
                if (!((i - pos) % dist)) ans--;
            }
            pos = i;
        }
        return ans;
    }
};

int main() {
    vector<int> v1 = {3};
    Solution s;
    cout<<s.addRungs(v1, 1);
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();