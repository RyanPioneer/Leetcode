/**
 * Source: t.ly/Is-yu
 * Date: 2023/9/26
 * Skill:
 * Runtime: 82 ms, faster than 46.89% of C++ online submissions
 * Memory Usage: 26.66 MB, less than 74.19% of C++ online submissions
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
    int oddEvenJumps(vector<int>& arr) {
        int sz = arr.size(), res = 0;
        vector<bool> odd(sz, false), even(sz, false);
        odd[sz - 1] = even[sz - 1] = true;
        map<int, int> num2idx;
        num2idx[arr[sz - 1]] = sz - 1;
        for (int i = sz - 2; i >= 0; i--) {
            auto it = num2idx.lower_bound(arr[i]);
            if (it != end(num2idx))
                odd[i] = even[it->second];
            it = num2idx.upper_bound(arr[i]);
            if (it != begin(num2idx))
                even[i] = odd[prev(it)->second];
            num2idx[arr[i]] = i;
        }
        for (int i = 0; i < sz; i++)
            if (odd[i])
                res++;
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {2, 10},
                             {1, 10},
                             {2, 3},
                             {6,10},
                             {4,3},
                             {8,6},
                             {5,8},
                             {7,6}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}