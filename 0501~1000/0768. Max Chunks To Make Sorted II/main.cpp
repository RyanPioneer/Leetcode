/**
 * Source: https://rb.gy/1fej1
 * Date: 2023/9/4
 * Skill:
 * Runtime: 21 ms, faster than 17.74% of C++ online submissions
 * Memory Usage: 15.9 MB, less than 7.76% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= arr.length <= 2000
 *      0 <= arr[i] <= 10 ** 8
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <set>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        priority_queue<pairs> pq;
        vector<vector<int>> nums;
        for (int i = 0; i < arr.size(); i++)
            nums.push_back(vector<int>{arr[i], i});
        sort(begin(nums), end(nums), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            else
                return a[0] < b[0];
        });
        int right = -1, prev_num = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][1] > right) {
                pq.push({right, prev_num});
                right = nums[i][1];
                prev_num = nums[i][0];
            } else {
                while (!pq.empty() && prev_num < nums[i][0] && pq.top().first > nums[i][1])
                    pq.pop();
            }
        }
        return pq.size();
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
    vector<int> v1{1,2,1,2,1,2}, v2{2,1,1,2,2,1};
}