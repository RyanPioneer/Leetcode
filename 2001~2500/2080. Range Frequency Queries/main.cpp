/**
 * Source: https://rb.gy/qaynt
 * Date: 2023/9/17
 * Skill:
 * Runtime: 450 ms, faster than 97.54% of C++ online submissions
 * Memory Usage: 235.92 MB, less than 53.45% of C++ online submissions
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
using PULL = pair<ULL, ULL>;


class RangeFreqQuery {
    unordered_map<int, vector<int>> num2pos;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
            num2pos[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {
        auto s = lower_bound(begin(num2pos[value]), end(num2pos[value]), left);
        auto e = upper_bound(begin(num2pos[value]), end(num2pos[value]), right);
        if (s == end(num2pos[value]))
            return 0;
        else
            return e - s;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main() {
    RangeFreqQuery s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}