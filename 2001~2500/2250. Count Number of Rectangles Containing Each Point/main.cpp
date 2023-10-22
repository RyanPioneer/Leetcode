/**
 * Source: tinyurl.com/yq3eltp5
 * Date: 2023/10/22
 * Skill:
 * Runtime: TLE
 * Memory Usage:
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= hi, yj <= 100
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
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> res(points.size(), 0);
        sort(rectangles.begin(), rectangles.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[1] == b[1])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        });
        for (int i = 0; i < points.size(); i++)
            points[i].push_back(i);
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {
            if (a[1] == b[1])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        });
        multiset<int> nums;
        for (auto i: rectangles)
            nums.insert(i[0]);
        int idx = 0, sz = rectangles.size();
        for (int i = 0; i < points.size() && idx < sz; i++) {
            while (idx < sz && points[i][1] > rectangles[idx][1])
                nums.erase(nums.lower_bound(rectangles[idx++][0]));
            auto it = nums.upper_bound(points[i][0] - 1);
            res[points[i][2]] = distance(it, nums.end());
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}