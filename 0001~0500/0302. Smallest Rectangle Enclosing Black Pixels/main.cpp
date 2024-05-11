/**
 * Source: t.ly/hfcNe
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 46 ms, faster than 73.91% of C++ online submissions
 * Memory Usage: 20.91 MB, less than 35.87% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
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
typedef pair<int, int> PII;
#define MK make_pair


class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int left = x, right = x, up = y, down = y;
        int dir[5] = {0, 1, 0, -1, 0};

        queue<PII> q;
        q.push(MK(x, y));
        image[x][y] = '0';
        while (!q.empty()) {
            PII d = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = d.first + dir[i], yy = d.second + dir[i + 1];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (image[xx][yy] == '0') continue;
                image[xx][yy] = '0';
                left = min(left, xx);
                right = max(right, xx);
                up = min(up, yy);
                down = max(down, yy);
                q.push(MK(xx, yy));
            }
        }
        return (down - up + 1) * (right - left + 1);
    }
};