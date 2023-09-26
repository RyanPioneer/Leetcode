/**
 * Source: t.ly/8M_39
 * Date: 2023/9/26
 * Skill:
 * Runtime: 124 ms, faster than 68.55% of C++ online submissions
 * Memory Usage: 81.70 MB, less than 85.53% of C++ online submissions
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
    int findLatestStep(vector<int>& day, int m) {
        int res = -1, sz = day.size(), minimum;
        if (sz == m)
            return m;
        vector<int> arr(sz);
        for (int i = 0; i < sz; i++)
            arr[day[i] - 1] = i + 1;
        deque<int> q;
        for (int i = 0; i < m; i++) {
            while (!q.empty() && arr[i] > arr[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        if (arr[m] > arr[q.front()])
            res = arr[m] - 1;
        for (int i = m; i < sz; i++) {
            if (q.front() <= i - m)
                q.pop_front();
            while (!q.empty() && arr[i] > arr[q.back()])
                q.pop_back();
            q.push_back(i);
            if (i < sz - 1)
                minimum = min(arr[i - m], arr[i + 1]);
            else
                minimum = arr[i - m];
            if (minimum > arr[q.front()])
                res = max(res, minimum - 1);
        }
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