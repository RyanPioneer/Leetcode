/**
 * Source: https://rb.gy/gjn0k
 * Date: 2023/9/13
 * Skill:
 * Runtime: 111 ms, faster than 50.90% of C++ online submissions
 * Memory Usage: 88.78 MB, less than 84.98% of C++ online submissions
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
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> left, right;
        for (int i = 0; i < k - 1; i++) {
            while (!left.empty() && nums[i] > nums[left.back()])
                left.pop_back();
            left.push_back(i);
            while (!right.empty() && nums[k + 1 + i] < nums[right.back()])
                right.pop_back();
            right.push_back(k + 1 + i);
        }
        for (int i = k; i < nums.size() - k; i++) {
            if (!left.empty() && i - left.front() > k)
                left.pop_front();
            while (!left.empty() && nums[i - 1] > nums[left.back()])
                left.pop_back();
            left.push_back(i - 1);
            if (!right.empty() && right.front() <= i)
                right.pop_front();
            while (!right.empty() && nums[i + k] < nums[right.back()])
                right.pop_back();
            right.push_back(i + k);
            if (left.size() == k && right.size() == k)
                res.push_back(i);
        }
        return res;
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
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    cout << 8 % -2;
}