/**
 * Source: t.ly/JdrzQ
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: Wrong answer
 * Memory Usage:
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

const int MX = 104;

class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int presum[MX][MX] = {0};
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= width; j++) {
                bool check = true;
                for (int k = j; k <= min(width, j + sideLength - 1); k++) {
                    presum[i][k] = presum[i - 1][k] + presum[i][k - 1] - presum[i - 1][k - 1];
                    int up = max(0, i - sideLength);
                    int left = max(0, k - sideLength);
                    int t = presum[i][k] - presum[up][k] - presum[i][left] + presum[up][left];
                    if (t >= maxOnes) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    presum[i][j]++;
                }
            }
        }
        return presum[height][width];
    }
};