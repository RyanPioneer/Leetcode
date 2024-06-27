/**
 * Source: ibit.ly/W-8ci
 * Date: 2024/6/27
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 28.83 MB, less than 93.37% of C++ online submissions
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


class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        function<int(vector<int>&, vector<int>&)> getDis = [&](vector<int>& v1, vector<int>& v2) {
            int d1 = abs(v1[0] - v2[0]);
            int d2 = abs(v1[1] - v2[1]);
            return d1 * d1 + d2 * d2;
        };

        function<bool(vector<int>&, vector<int>&, vector<int>&, vector<int>&)> check = [&](vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4) {
            int d1 = getDis(v1, v2);
            int d2 = getDis(v1, v3);
            int d3 = getDis(v4, v2);
            int d4 = getDis(v4, v3);
            int vec1X = v2[0] - v1[0];
            int vec1Y = v2[1] - v1[1];
            int vec2X = v3[0] - v1[0];
            int vec2Y = v3[1] - v1[1];
            bool right = (vec1X * vec2X + vec1Y * vec2Y) == 0;
            return d1 == d2 && d2 == d3 && d3 == d4 && d1 > 0 && right;
        };

        if (check(p1,p2,p3,p4)) return true;
        else if (check(p1,p4,p3,p2)) return true;
        else if (check(p1,p4,p2,p3)) return true;
        else return false;
    }
};