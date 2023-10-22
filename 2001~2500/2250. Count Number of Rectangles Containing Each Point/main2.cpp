/**
 * Source: tinyurl.com/yq3eltp5
 * Date: 2023/10/22
 * Skill:
 * Runtime: 392 ms, faster than 89.96% of C++ online submissions
 * Memory Usage: 93.19 MB, less than 26.64% of C++ online submissions
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
            if (a[0] == b[0])
                return a[1] < b[1];
            else
                return a[0] < b[0];
        });
        for (int i = 0; i < points.size(); i++)
            points[i].push_back(i);
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            else
                return a[0] < b[0];
        });
        vector<int> nums(101, 0);
        for (auto i: rectangles)
            nums[i[1]]++;
        int idx = 0, sz = rectangles.size();
        for (int i = 0; i < points.size() && idx < sz; i++) {
            while (idx < sz && points[i][0] > rectangles[idx][0])
                nums[rectangles[idx++][1]]--;
            for (int j = points[i][1]; j <= 100; j++)
                res[points[i][2]] += nums[j];
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