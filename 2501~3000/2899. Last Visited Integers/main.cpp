/**
 * Source: ibit.ly/_A2Mt
 * Date: 2023/10/15
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 23.59 MB, less than 100.00% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int nums[101], cnt = 0, idx = -1;
        vector<int> res;
        for (auto w: words) {
            if (w == "prev") {
                if (idx == -1)
                    res.push_back(-1);
                else
                    res.push_back(nums[idx--]);
            } else {
                nums[cnt++] = stoi(w);
                idx = cnt - 1;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
    int c = test(2, 2);
    cout << c << endl;
}