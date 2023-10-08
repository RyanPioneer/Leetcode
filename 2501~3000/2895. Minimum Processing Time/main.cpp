/**
 * Source: ibit.ly/DcZAa
 * Date: 2023/10/8
 * Skill:
 * Runtime: 144 ms, faster than 83.33% of C++ online submissions
 * Memory Usage: 98.18 MB, less than 66.67% of C++ online submissions
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
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(begin(processorTime), end(processorTime));
        sort(begin(tasks), end(tasks));
        int res = 0, n = processorTime.size(), idx = tasks.size() - 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 4; j++)
                res = max(res, processorTime[i] + tasks[idx--]);
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
}