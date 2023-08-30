/**
 * Source: https://rb.gy/be63d
 * Date: 2023/8/30
 * Skill:
 * Runtime: 439 ms, faster than 30.63% of C++ online submissions
 * Memory Usage: 140.03 MB, less than 28.61% of C++ online submissions
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
    int minSumOfLengths(vector<int>& arr, int target) {
        map<int, int> mymap;
        mymap[0] = -1;
        ll presum = 0;
        int res = INT32_MAX, cur_min = INT32_MAX / 2;
        deque<pairs> q;
        for (int i = 0; i < arr.size(); i++) {
            presum += arr[i];
            if (mymap.find(presum - target) != mymap.end()) {
                int front = mymap[presum - target];
                int length = i - front;
                while (!q.empty() && q.front().second <= front) {
                    cur_min = q.front().first;
                    q.pop_front();
                }
                res = min(res, length + cur_min);
                if (length < cur_min && (q.empty() || q.back().first > length))
                    q.push_back({length, i});
            }
            mymap[presum] = i;
        }
        return res < INT32_MAX / 2 ? res : -1;
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
    int res = s.minSumOfLengths(arr, target);
    cout << res << endl;
}