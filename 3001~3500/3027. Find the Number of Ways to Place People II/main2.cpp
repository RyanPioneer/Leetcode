/**
 * Source: jpeg.ly/QXfAg
 * Date: 2024/2/4
 * Skill: 2D Prefix sum
 * Ref:
 * Runtime: 774 ms, faster than 56.34% of C++ online submissions
 * Memory Usage: 307.39 MB, less than 10.30% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      2 <= n <= 1000
 */


#include <iostream>
#include <vector>
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


class Prefix2D {
public:
    Prefix2D(std::vector<std::vector<int>>& matrix) : matrix(matrix) {
        prefix = build_prefix_2d();
    }

    std::vector<std::vector<int>> build_prefix_2d() {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<std::vector<int>> prefix(rows + 1, std::vector<int>(cols + 1, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                prefix[i + 1][j + 1] = prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j] + matrix[i][j];
            }
        }
        return prefix;
    }

    int get_sum(int x1, int y1, int x2, int y2) {
        return prefix[x2 + 1][y2 + 1] - prefix[x1][y2 + 1] - prefix[x2 + 1][y1] + prefix[x1][y1];
    }

private:
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> prefix;
};

class Solution {
public:
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        std::vector<int> x_coords, y_coords;

        for (const auto& p : points) {
            x_coords.push_back(p[0]);
            y_coords.push_back(p[1]);
        }

        std::sort(x_coords.begin(), x_coords.end());
        std::sort(y_coords.begin(), y_coords.end());

        std::unordered_map<int, int> x_compressed, y_compressed;
        for (int i = 0; i < x_coords.size(); ++i) {
            x_compressed[x_coords[i]] = i;
        }
        for (int i = 0; i < y_coords.size(); ++i) {
            y_compressed[y_coords[i]] = i;
        }

        std::vector<std::vector<int>> matrix(x_coords.size() + 1, std::vector<int>(y_coords.size() + 1, 0));
        for (const auto& p : points) {
            matrix[x_compressed[p[0]]][y_compressed[p[1]]] = 1;
        }

        Prefix2D pref(matrix);
        int ans = 0;
        int n = points.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 - y1 > x2 - y2) {
                    std::swap(x1, x2);
                    std::swap(y1, y2);
                }

                if (x1 <= x2 && y1 >= y2) {
                    int sum_in_rect = pref.get_sum(x_compressed[x1], y_compressed[y2], x_compressed[x2], y_compressed[y1]);
                    if (sum_in_rect == 2) {
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};
