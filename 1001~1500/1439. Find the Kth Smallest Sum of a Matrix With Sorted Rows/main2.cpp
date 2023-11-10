/**
 * Source: t.ly/oHyt8
 * Date: 2023/11/10
 * Skill:
 * Runtime: 111 ms, faster than 48.61% of C++ online submissions
 * Memory Usage: 10.38 MB, less than 81.82% of C++ online submissions
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
#include <functional>
#include <list>


using namespace std;

#define ll long long

typedef pair<int, int> pairs;

const int MX = 1e5 + 1;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        vector<int> nums1, nums2;
        nums1.push_back(0);
        for (int i = 0; i < mat.size(); i++) {
            for (auto j: nums1) {
                for (int k = 0; k < n; k++) {
                    nums2.push_back(j + mat[i][k]);
                }
            }
            sort(begin(nums2), end(nums2));
            nums2.resize(min(k, (int)nums2.size()));
            nums1 = nums2;
            nums2.clear();
        }
        return nums1[k - 1];
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}