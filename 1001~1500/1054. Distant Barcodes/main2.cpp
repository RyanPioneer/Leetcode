/**
 * Source: https://rb.gy/fnekp
 * Date: 2023/9/13
 * Skill:
 * Runtime: 50 ms, faster than 93.52% of C++ online submissions
 * Memory Usage: 42.07 MB, less than 75.00% of C++ online submissions
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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> num2freq;
        vector<pairs> nums;
        for (auto n: barcodes)
            num2freq[n]++;
        for (auto n: num2freq)
            nums.push_back(make_pair(n.second, n.first));
        sort(begin(nums), end(nums), [](pairs a, pairs b) {return a.first > b.first;});
        int pos = 0, sz = barcodes.size();
        for (auto n: nums) {
            for (int i = 0; i < n.first; i++) {
                barcodes[pos] = n.second;
                pos += 2;
                if (pos >= sz)
                    pos = 1;
            }
        }
        return barcodes;
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