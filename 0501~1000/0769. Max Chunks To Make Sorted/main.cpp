/**
 * Source: https://rb.gy/vprz5
 * Date: 2023/9/4
 * Skill:
 * Runtime: 3 ms, faster than 37.97% of C++ online submissions
 * Memory Usage: 7.38 MB, less than 17.72% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= arr.length <= 10
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
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> mystack;
        for (auto i: arr) {
            if (mystack.empty() || mystack.top() < i)
                mystack.push(i);
            else {
                int maximum = mystack.top();
                while (!mystack.empty() && mystack.top() > i)
                    mystack.pop();
                mystack.push(maximum);
            }
        }
        return mystack.size();
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