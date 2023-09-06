/**
 * Source: https://rb.gy/nct3m
 * Date: 2023/9/6
 * Skill:
 * Runtime: 28 ms, faster than 75.00% of C++ online submissions
 * Memory Usage: 9.31 MB, less than 67.05% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= points.length <= 50
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


class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        set<pairs> point_set;
        for (auto p: points)
            point_set.insert(make_pair(p[0], p[1]));
        double res = 1e10;
        for (int i = 0; i < points.size() - 2; i++) {
            for (int j = i + 1; j < points.size() - 1; j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    if ((points[j][0] - points[i][0]) * (points[k][0] - points[i][0])
                        + (points[j][1] - points[i][1]) *  (points[k][1] - points[i][1]) == 0) {
                        int x = (points[j][0] + points[k][0]) - points[i][0];
                        int y = (points[j][1] + points[k][1]) - points[i][1];
                        if (point_set.find(make_pair(x, y)) != point_set.end()) {
                            double l1 = (points[j][0] - points[i][0]);
                            double w1 = (points[j][1] - points[i][1]);
                            double l = sqrt(l1 * l1 + w1 * w1);
                            double l2 = (points[k][0] - points[i][0]);
                            double w2 = (points[k][1] - points[i][1]);
                            double w = sqrt(l2 * l2 + w2 * w2);
                            res = min(res, l * w);
                        }
                    }
                }
            }
        }
        return res != 1e10 ? res : 0;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
//    Solution s;
    pairs p = make_pair(1, 2);
    set<pairs> myset;
    myset.insert(p);
    if (myset.find(make_pair(1, 2)) != myset.end())
        cout << "true" << endl;
    else
        cout << "false" << endl;
}