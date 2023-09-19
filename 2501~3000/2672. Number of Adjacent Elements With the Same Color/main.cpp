/**
 * Source: https://rb.gy/c1cm7
 * Date: 2023/9/19
 * Skill:
 * Runtime: 414 ms, faster than 58.79% of C++ online submissions
 * Memory Usage: 176.13 MB, less than 45.05% of C++ online submissions
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


class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> arr(n, 0), res;
        int sz = queries.size(), cur_num = 0;
        for (int i = 0; i < sz; i++) {
            int pos = queries[i][0], color = queries[i][1];
            if (pos > 0 && arr[pos] != 0 && arr[pos] == arr[pos - 1])
                cur_num--;
            if (pos < n - 1 && arr[pos] != 0 && arr[pos] == arr[pos + 1])
                cur_num--;
            arr[pos] = color;
            if (pos > 0 && arr[pos] == arr[pos - 1])
                cur_num++;
            if (pos < n - 1 && arr[pos] == arr[pos + 1])
                cur_num++;
            res.push_back(cur_num);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums2{8, 8, 9, 1, 6, 3, 0, 4, 1, 4, 1, 8, 0, 3, 1, 2, 7, 9, 3, 2, 5, 5, 2, 7, 9, 5, 2, 2};
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
}