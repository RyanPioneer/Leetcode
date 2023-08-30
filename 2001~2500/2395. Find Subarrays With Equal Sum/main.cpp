/**
 * Source: https://rb.gy/dbms1
 * Date: 2023/8/30
 * Skill:
 * Runtime: 0 ms, faster than 100% of C++ online submissions
 * Memory Usage: 7.92 MB, less than 15.42% of C++ online submissions
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
#include <deque>

using namespace std;

#define ll long long
// using ll = long long;

typedef pair<int, int> pairs;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> num_set;
        int cur_num = nums[0] + nums[1];
        num_set.insert(cur_num);
        for (int i = 2; i < nums.size(); i++) {
            cur_num += nums[i] - nums[i - 2];
            if (num_set.find(cur_num) != num_set.end())
                return true;
            num_set.insert(cur_num);
        }
        return false;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> arr{3,2,2,4,3};
    int target = 3;

    cout << target << endl;
}