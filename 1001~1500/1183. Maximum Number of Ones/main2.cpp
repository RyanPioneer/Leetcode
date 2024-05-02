/**
 * Source: t.ly/JdrzQ
 * Date: 2024/4/28
 * Skill:
 * Ref: t.ly/3BdEA
 * Runtime: 5 ms, faster than 67.65% of C++ online submissions
 * Memory Usage: 8.44 MB, less than 85.29% of C++ online submissions
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
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int xCount = width / sideLength, yCount = height / sideLength;
        int xRest = width % sideLength, yRest = height % sideLength;
        vector<int> nums(sideLength * sideLength, 0);

        for (int i = 0; i < sideLength; i++) {
            for (int j = 0; j < sideLength; j++) {
                if (i < yRest && j < xRest) {
                    nums[i * sideLength + j] = (xCount + 1) * (yCount + 1);
                } else if (j < xRest) {
                    nums[i * sideLength + j] = (xCount + 1) * yCount;
                } else if (i < yRest) {
                    nums[i * sideLength + j] = xCount * (yCount + 1);
                } else {
                    nums[i * sideLength + j] = xCount * yCount;
                }
            }
        }

        sort(begin(nums), end(nums), [](int a, int b) {
            return a > b;
        });

        int res = 0;

        for (int i = 0; i < maxOnes; i++) {
            res += nums[i];
        }
        return res;
    }
};