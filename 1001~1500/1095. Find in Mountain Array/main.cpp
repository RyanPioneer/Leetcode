/**
 * Source: ibit.ly/ABqHs
 * Date: 2023/10/5
 * Skill:
 * Runtime: 6 ms, faster than 44.51% of C++ online submissions
 * Memory Usage: 7.55 MB, less than 5.13% of C++ online submissions
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
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;



// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
public:
    int get(int index);
    int length();
};


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int sz = mountainArr.length();
        auto binary_search = [&](int l, int r, function<bool(int)> cond) {
            while (l < r) {
                int mid = (l + r) / 2;
                if (cond(mid))
                    r = mid;
                else
                    l = mid + 1;
            }
            return l;
        };

        int peak = binary_search(1, sz - 2, [&](int i) {
            return mountainArr.get(i) > mountainArr.get(i + 1);
        });

        int left = binary_search(0, peak, [&](int i) {
            return mountainArr.get(i) >= target;
        });
        if (mountainArr.get(left) == target)
            return left;

        int right = binary_search(peak + 1, sz - 1, [&](int i) {
            return mountainArr.get(i) <= target;
        });
        if (mountainArr.get(right) == target)
            return right;
        else
            return -1;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}