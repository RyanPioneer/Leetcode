/**
 * Source: https://rb.gy/1fej1
 * Date: 2023/9/4
 * Skill:
 * Runtime: 4 ms, faster than 88.72% of C++ online submissions
 * Memory Usage: 12.3 MB, less than 55.11% of C++ online submissions
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
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> mystack;
        for (auto num: arr) {
            if (mystack.empty() || num >= mystack.top())
                mystack.push(num);
            else {
                int maximum = mystack.top();
                while (!mystack.empty() && mystack.top() > num)
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