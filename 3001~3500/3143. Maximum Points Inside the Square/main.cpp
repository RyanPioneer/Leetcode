/**
 * Source: ibit.ly/STILF
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 205 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 97.70 MB, less than 100.00% of C++ online submissions
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
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int left = -1, right = 1e9;
        int cnt[26], len = points.size(), res = 0;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            bool check = true;
            for (int i = 0; i < 26; i++) {
                cnt[i] = 0;
            }
            for (int i = 0; i < len; i++) {
                int x = abs(points[i][0]), y = abs(points[i][1]);
                if (x <= mid && y <= mid) {
                    cnt[s[i] - 'a']++;
                    if (cnt[s[i] - 'a'] > 1) {
                        check = false;
                        break;
                    }
                }
            }
            if (check) left = mid;
            else right = mid - 1;
        }

        for (int i = 0; i < len; i++) {
            int x = abs(points[i][0]), y = abs(points[i][1]);
            if (x <= left && y <= left) {
                res++;
            }
        }
        return res;
    }
};